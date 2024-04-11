#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = 998244353;

ll powr(ll a, ll b){
    if(b == 0) return 1;
    ll p = powr(a, b/2);
    p = (p * 1ll * p) % MOD;
    if(b % 2 == 1) p = (p * 1ll * a) % MOD;
    return p;
}

ll inv(ll x){
    return powr(x, MOD - 2);
}

int main(){
    fastIO;
    ll n, m;
    cin >> n >> m;
    vector<ll> g;
    vector<ll> pw;
    pw.push_back(0);
    g.push_back(0);
    ll x;
    for(ll i = 0 ; i < n ; i ++ ){
        cin >> x;
        g.push_back(x);
        pw.push_back(0);
    }
    sort(g.begin(), g.end());
    for(ll i = 1; i <= n; i ++ ){
        pw[i] = pw[i - 1] + g[i];
    }
    ll ai, bi;
    ll low, high;
    ll vf;
    ll s1, s2;
    for(ll t = 0; t < m ; t ++ ){
        cin >> ai >> bi;
        ll id = lower_bound(g.begin(), g.end(), bi) - g.begin();
        id -- ;
        low = id;
        high = n - id;
        if(high < ai){
            cout << "0\n";
        }
        else{
            s1 = (1 - (ai * 1ll * inv(high)) % MOD + MOD) % MOD;
            s2 = (1 - (ai * 1ll * inv(high + 1)) % MOD + MOD) % MOD;
            s1 = (s1 * 1ll * ((pw[n]-pw[id]) % MOD)) % MOD;
            s2 = (s2 * 1ll * (pw[id]%MOD)) % MOD;
            vf = (s1 + s2) % MOD;
            cout << vf << "\n";
        }
    }
    return 0;
}