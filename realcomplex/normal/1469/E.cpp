#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool is_pr(ll x){
    for(ll i = 2; i * i <= x; i ++ ){
        if(x % i == 0) return false;
    }
    return true;
}

ll gen_mod(){
    ll y = (ll)1e9 + ((ll)rng() % (ll)1e9 + (ll)1e9) % (ll)1e9;
    while(!is_pr(y)) y ++ ;
    return y;
}

const ll P = 23;
const ll MOD = gen_mod();
const ll N = (ll)1e6 + 100;

ll bit[N];
ll pwr[N];
ll sum[N];

void solve(){
    ll n, k;
    cin >> n >> k;
    char f;
    pwr[0]=1;
    for(ll i = 1; i <= n; i ++ ){
        pwr[i]=(pwr[i-1]*1ll*P)%MOD;
    }
    set<ll> ban;
    ll cc;
    sum[0]=0;
    for(ll i = 1; i <= n; i ++ ){
        cin >> f;
        bit[i]=f-'0';
        bit[i]^=1;
        sum[i]=pwr[i-1]*1ll*bit[i];
        sum[i]%=MOD;
        sum[i]=(sum[i-1]+sum[i])%MOD;
        if(i >= k){
            cc = (sum[i]-sum[i-k]+MOD)%MOD;
            cc = (cc * 1ll * pwr[n-i])%MOD;
            ban.insert(cc);
        }
    }
    ll lg = 0;
    while((1 << lg) <= n && lg < k){
        lg ++ ;
    }
    ll best = -1;
    ll cur;
    ll bb;
    for(ll las = 0 ; las < (1 << lg); las ++ ){
        cur = 0;
        bb = 0;
        for(ll j = lg - 1;  j >= 0; j -- ){
            if((las & (1 << j))){
                cur = (cur + pwr[bb]) % MOD;
            }
            bb ++ ;
        }
        cur = (cur * 1ll * pwr[n-lg])%MOD;
        if(!ban.count(cur)){
            cout << "YES\n";
            for(ll i = 0 ; i < k - lg; i ++ )
                cout << 0;
            for(ll j = lg - 1 ; j >= 0 ; j -- ){
                if((las & (1 << j))) cout << 1;
                else cout << 0;
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";

}

int main(){
    fastIO;
    ll q;
    cin >> q;
    for(ll t = 1; t <= q; t ++ ){
        solve();
    }
    return 0;
}