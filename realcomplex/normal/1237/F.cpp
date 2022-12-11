#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 3610;
const int M = N * 2;
const int MOD = 998244353;
bool ban_i[N];
bool ban_j[N];
int fac[M];
int inv[M];

int pick(int n, int k){
    if(k > n) return 0;
    return ((fac[n]*1ll*inv[k])%MOD*inv[n-k])%MOD;
}

int powr(int x, int k){
    if(k == 0) return 1;
    int p = powr(x, k / 2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * x) % MOD;
    return p;
}

int dp_i[N][N]; // take pairs
int dp_j[N][N];

void add(int &x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    int i1, j1, i2, j2;
    int ib = 0;
    int jb = 0;
    for(int i = 1; i <= k ; i ++ ){
        cin >> i1 >> j1 >> i2 >> j2;
        ban_i[i1] = true;
        ban_j[j1] = true;
        ban_i[i2] = true;
        ban_j[j2] = true;
    }
    for(int i = 1; i <= n; i ++ ){
        if(!ban_i[i]) ib ++ ;
    }
    for(int i = 1; i <= m; i ++ ){
        if(!ban_j[i]) jb ++ ;
    }
    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < M; i ++ ){
        fac[i] = (fac[i - 1] * 1ll * i) % MOD;
        inv[i] = (inv[i - 1] * 1ll * powr(i, MOD - 2)) % MOD;
    }
    dp_i[0][0] = 1;
    dp_j[0][0] = 1;
    for(int i = 1; i <= n; i ++ ){
        for(int t = 0; t <= i / 2; t ++ ){
            add(dp_i[i][t], dp_i[i - 1][t]);
            if(t > 0 && i >= 2 && !ban_i[i] && !ban_i[i-1]){
                add(dp_i[i][t], dp_i[i - 2][t - 1]);
            }
        }
    }
    for(int i = 1; i <= m ; i ++ ){
        for(int t = 0 ;t <= i / 2; t ++ ){
            add(dp_j[i][t], dp_j[i-1][t]);
            if(t > 0 && i >= 2 && !ban_j[i] && !ban_j[i - 1]){
                add(dp_j[i][t], dp_j[i - 2][t - 1]);
            }
        }
    }
    int isol;
    int jsol;
    int res = 0;
    int total;
    for(int ii = 0; ii * 2 <= n; ii ++ ){
        if(dp_i[n][ii] == 0) continue;
        for(int jj = 0 ; jj * 2 <= m ; jj ++ ){
            if(ii * 2 + jj > n || jj * 2 + ii > m) continue;
            if(dp_j[m][jj] == 0) continue;
            isol = dp_i[n][ii];
            isol = (isol * 1ll * pick(ib - ii * 2, jj)) % MOD;
            jsol = dp_j[m][jj];
            jsol = (jsol * 1ll * pick(jb - jj * 2, ii)) % MOD;
            total = (isol * 1ll * jsol) % MOD;
            total = (total * 1ll * fac[ii]) % MOD;
            total = (total * 1ll * fac[jj]) % MOD;
            add(res, total);
        }
    }
    cout << res << "\n";
    return 0;
}