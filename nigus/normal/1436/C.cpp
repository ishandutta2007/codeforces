#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;


unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

ll bigger, smaller = 0;

ll solve(){
    ll l = 0;
    ll r = n;
    ll res = 1;
    while(l < r){
        ll mid = (l+r)/2;
        if(mid < k){
            res *= smaller;
            smaller--;
            l = mid+1;
        }
        if(mid > k){
            res *= bigger;
            bigger--;
            r = mid;
        }
        if(mid == k){
            l = mid+1;
        }
        res %= big;
    }
    return res;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n >> m >> k;
    m--;
    smaller = m;
    bigger = n-smaller-1;

    ll ans = solve();

    for(ll c1 = 0; c1 < smaller+bigger; c1++){
        ans *= (c1+1);
        ans %= big;
    }

    cout << ans << "\n";

    return 0;
}