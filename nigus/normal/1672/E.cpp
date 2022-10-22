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

const int MAXN = 500006;

bool DEBUG = 0;

ll Q = 0;
ll ans = big*big;

ll ask(ll w){
    if(w <= 0)return 0;
    Q++;
    cout << "? " << w << "\n";
    fflush(stdout);
    ll h = 0;
    cin >> h;

    if(h != 0){
        ans = min(ans, h*w);
    }

    return h;
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;

    ll lo = 1;
    ll hi = 2000*2000+2100;
    ask(1);
    while(lo < hi-1){
        ll mid = (lo+hi)/2;
        ll h = ask(mid);
        if(h == 1){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    ll tot = hi;

    for(ll lines = 2; lines <= n; lines++){
        ll w = (tot-1) / lines;
        ask(w);
    }
    cout << "! " << ans << "\n";
    fflush(stdout);


    return 0;
}