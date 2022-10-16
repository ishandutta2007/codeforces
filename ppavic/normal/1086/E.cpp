#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2005;
const int MOD = 998244353;

int mat[N][N], per[N],  der[N][N], loga[N][3], n, inv[N], bio[N], dp[N][N];

void update(int x,int y,int k){
    for(; x < N ; x += x & -x)
        loga[x][k] += y;
}

int query(int x,int k){
    int ret = 0;x--;
    for(; x ; x -= x & -x)
        ret += loga[x][k];
    return ret;
}


int add(int A,int B){
    if(A + B >= MOD) return A + B - MOD;
    return A + B;
}

int sub(int A,int B){
    if(A - B < 0) return A - B + MOD;
    return A - B;
}

int mul(int A,int B){
    return ((ll)A  * B) % MOD;
}

int pot(int A, int B){
    int base = A, ret = 1;
    for(;B;B>>=1){
        if(B&1) ret = mul(ret, base);
        base = mul(base, base);
    }
    return ret;
}

int choose(int n,int k){
    if(k > n) return 0;
    return mul(per[n], mul(inv[k], inv[n - k]));
}

void precompute(){
    der[0][0] = 1;der[1][0] = 0;
    per[0] = 1;per[1] = 1;
    inv[0] = 1;inv[1] = 1;
    for(int i = 2;i<N;i++){
        per[i] = mul(per[i - 1], i);
        inv[i] = pot(per[i], MOD - 2);
        der[i][0] = mul(i - 1, add(der[i - 1][0], der[i - 2][0]));
    }
    for(int i = 0;i<N;i++){
        for(int j = 1;j<N;j++){
            if(i >= j)
                der[i][j] = mul(der[i - j][0], choose(i, j)) + der[i][j - 1];
        }
    }

}

int f(int n,int k){
    if(k > n || k < 0) return 0;
    if(k == 0) return der[n][0];
    if(dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = add( mul((n - k) , f(n - 1, k)) , mul( k , f(n - 1, k - 1)) );
}

bool inside(int x,int k){
    return query(x + 1, k) - query(x, k);
}

void move(int x,int y){
    int k = 2;
    if(inside(x, 0)) k = 0;
    if(inside(x, 1)) k = 1;
    if(k == 2) return;
    update(x, -1, k);
    update(x, 1, k + y);

}

int order(int x){
    memset(loga, 0, sizeof(loga));
    memset(bio, 0, sizeof(bio));
    for(int i = 1;i<=n;i++)
        update(i, 1, 1);
    if(!x){
        int ret = 0;
        for(int i = 0;i<n;i++){
            ret = add(ret, mul(query(mat[x][i], 1), per[n - i - 1]));
            update(mat[x][i], -1, 1);
        }

        return ret;
    }
    int ret = 0, cnt = (x == 0) * n;
    for(int i = 0;i<n;i++){
        int in = 0, ad = 0, cur = 0;
        if(!(inside(mat[x - 1][i], 0) || inside(mat[x - 1][i], 1))){
            cnt++;
        }
        /**
        else{
            move(mat[x - 1][i], -1);
        }**/
        if(bio[mat[x][i]]) {
            cnt++, cur++;
        }
        int rmb = 0;
        for(;rmb < 2 && !inside(mat[x - 1][i], rmb);rmb++);
        if(rmb != 2) update(mat[x - 1][i], -1, rmb);
        int slob = i + 1 - cnt;
        ret = add(ret, mul(query(mat[x][i], 0), f(n - i - 1, slob - 1 + cur)));
        ret = add(ret, mul(query(mat[x][i], 1), f(n - i - 1, slob + cur)));
        //printf("f %d %d => %d\n", n - i - 1, cnt / 2 -  cur, f(n - i - 1, cnt / 2 - cur));
        //ret = add(ret, mul(query(mat[x][i], 2), f(n - i - 1, slob + 1 - cur)));
        if(rmb != 2) update(mat[x - 1][i], 1, rmb);
        for(int b = 0;b < 2;b++)
            if(inside(mat[x][i], b))
                update(mat[x][i], -1, b);
        bio[mat[x - 1][i]] = 1;
        move(mat[x - 1][i], -1);

    }
    return ret ;
}

int main(){
    memset(dp, -1, sizeof(dp));
    precompute();
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int sol = 0;
    for(int i = 0;i<n;i++){
        sol = add(sol, mul(order(i), pot(der[n][0], n - i - 1)));
    }
    printf("%d\n", sol);
    return 0;
}