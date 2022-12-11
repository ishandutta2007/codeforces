#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = (ll)1e9 + 7;

ll powr(ll n, ll k){
    if(k == 0)
        return 1ll;
    ll dd = powr(n,k/2);
    dd = (dd * dd) % MOD;
    if(k&1)
        dd = (dd * n) % MOD;
    return dd;
}

const int N = 105;
ll f[N];

ll calc(ll n, ll k){
    if(n<k)
        return 0;
    ll ret = f[n];
    ret = (ret * powr(f[k], MOD-2)) % MOD;
    ret = (ret * powr(f[n-k], MOD-2)) % MOD;
    return ret;
}

ll dp[N][N * N];
ll C[N][N];

ll W1[N][N], W2[N][N];

int main(){
    fastIO;
    ll n, m, k;
    cin >> n >> m >> k;
    f[0] = 1;
    for(ll i = 1 ; i < N; i ++ ) {
        f[i] = (f[i-1] * i) % MOD;
    }
    ll pd;
    ll di;
    ll dl, rm;
    dl = m / n;
    rm = m % n;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ;j  <= i ; j ++ ){
            C[i][j] = calc(i,j);
            W1[i][j] = powr(C[i][j], dl);
            W2[i][j] = (W1[i][j] * C[i][j]) % MOD;
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j <= k ; j ++ ){
            for(int z = 0 ; z <= n ; z ++ ){
                if(z > j)
                    break;
                if(rm >= i) pd = W2[n][z];
                else pd = W1[n][z];
                dp[i][j] = (dp[i][j] + ((dp[i-1][j-z] * pd) % MOD)) % MOD;
            }
        }
    }
    cout << dp[n][k];
    return 0;
}