#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int MOD = (int)998244353;

int inv[N];
int fac[N];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k/2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

int S[N * 2];
int lim;
int A[N];
int B[N];
int V[N];

int mult = 1;

void upd(int u, int c){
    int id = u + lim;
    V[u] += c;
    if(c == +1){
        mult = (mult * 1ll * V[u]) % MOD;
    }
    else{
        mult = (mult * 1ll * inv[V[u] + 1]) % MOD;
    }
    S[id] = V[u];
    id /= 2;
    while(id > 0){
        S[id] = (S[id * 2] + S[id * 2 + 1]) % MOD;
        id /= 2;
    }
}

int get(int lf, int rf){
    lf += lim;
    rf += lim;
    int res = 0;
    while(lf <= rf){
        if(lf % 2 == 1) res = (res + S[lf++]) % MOD;
        if(rf % 2 == 0) res = (res + S[rf--]) % MOD;
        lf /= 2;
        rf /= 2;
    }
    return res;
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    fac[0] = 1ll;
    for(int i = 1; i < N; i ++ ){
        inv[i] = powr(i, MOD - 2);
        fac[i] = (fac[i - 1] * 1ll * i) % MOD;
    }
    lim = (int)2e5;
    for(int i = 0 ; i < n; i ++ ){
        cin >> A[i];
        A[i] -- ;
        upd(A[i], +1);
    }
    for(int i = 0 ; i < m ; i ++ ){
        cin >> B[i];
        B[i] -- ;
    }
    int res = 0;
    int up;
    int down;
    for(int i = 0 ; i <= n; i ++ ){
        if(i >= m) break;
        if(i == n){
            res = (res + 1) % MOD;
        }
        else{
            up = fac[n - i - 1];
            up = (up * 1ll * powr(mult, MOD - 2)) % MOD;
            up = (up * 1ll * get(0, B[i] - 1)) % MOD;
            res = (res + up) % MOD;
        }
        if(V[B[i]] > 0){
            upd(B[i], -1);
        }
        else{
            break;
        }
        if(i==n) continue;
    }
    cout << res << "\n";
    return 0;
}