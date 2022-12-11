#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair

#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int MOD = 998244353;
int fac[N];
int inv[N];
ll d[N];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k / 2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

int pick(int n, int k){
    int res = fac[n];
    res = (res * 1ll * inv[k]) % MOD;
    res = (res * 1ll * inv[n - k]) % MOD;
    return res;
}


int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    fac[0]=1;
    inv[0]=1;

    for(int i = 1; i <= m; i ++ ){
        fac[i]=(fac[i-1] * 1ll * i) % MOD;
        inv[i]=powr(fac[i], MOD-2);
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> d[i];
        d[i] += d[i - 1];
    }
    if(n == 1){
        cout << m << "\n";
        return 0;
    }
    else if(n == 2){
        cout << (m * 1ll * m) % MOD;
        return 0;
    }
    int kk = 0;
    int ii, jj;
    for(int i = 1; i <= n; i ++ ){
        ii = i;
        for(int j = 18; j >= 0 ; j -- ){
            jj = (ii + (1 << j));
            if(jj <= n){
                if((d[jj - 1] - d[i-1]) * 2ll <= d[n]){
                    ii = jj;
                }
            }
        }
        if((d[ii - 1] - d[i - 1]) * 2ll == d[n]){
            kk ++ ; // we count pairs of i < j
        }
    }
    int res = 0;
    int cur;
    int p;
    int col;
    for(int eq = 0; eq <= kk ; eq ++ ){ 
        if(eq <= m){
            cur = (pick(kk, eq) * 1ll * pick(m, eq)) % MOD;
            cur = (cur * 1ll * fac[eq]) % MOD;
            col = (m - eq);
            p = (col * 1ll * (col - 1)) % MOD;
            cur = (cur * 1ll * powr(p, kk - eq)) % MOD;
            cur = (cur * 1ll * powr(col, n - 2 * kk)) % MOD;
            res = (res + cur) % MOD;
        }
    }
    cout << res << "\n";
    return 0;
}