#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000001;

ll ANS[MAXN] = {0};

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
    ll k2 = k;
    if(k < (n+n*n)/2){
        cout << "-1\n";
        return 0;
    }

    k -= (n+n*n)/2;

    ll l = 0;
    ll r = n-1;


    for(ll c1 = n-1; c1 >= 0; c1--){
        while(ANS[r] != 0){
            r--;
        }
        while(ANS[l] != 0){
            l++;
        }
        if(k - max(0ll,c1 - l) >= 0){
            ANS[l] = c1+1;
            k -= max(0ll,c1 - l);
        }
        else{
            ANS[r] = c1+1;
        }
    }

    cout << k2-k << "\n";
    ll ans = 0;
    rep(c1,0,n){
        cout << c1+1 << " ";
    }cout << "\n";

    rep(c1,0,n){
        ans += max(c1+1ll, ANS[c1]);
        cout << ANS[c1] << " ";
    }cout << "\n";

   // cerr << ans << "\n";

    return 0;
}