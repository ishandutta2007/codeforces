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

const int MAXN = 2501;

bool check(ll k){
    ll hej = (k*k-k)/2;
    if(n-hej <= 0)return 0;
    return ((n-hej) % (k) == 0);
}

ll solve(){
    ll t = 2;
    while(t <= n){

        ll hej = (t*t-t)/2;
        if(n-hej <= 0)break;

        if(check(t))return t;
       // if(check(t-1) && t > 2)return t-1;

        t *= 2;
    }


    ll k = n;
    while(k%2 == 0){
        k /= 2;
    }
    if(k > 1)return k;

    return -1;
}


bool prime(ll i){

    for(ll c1 = 2; c1*c1 <= i; c1++){
        if(i%c1 == 0)return 0;
    }
    return 1;
}



int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;
    rep(c4,0,T){

        /*
        rep(c1,2,100){
            n = c1 + 100000000000000;
            ll res = -1;
            rep(k,2,100000){
                if(check(k)){
                    res = k;
                    break;
                }
            }
            cerr << n << ": " << res << "\n";

        }

        cin >> n;
        ll t = 1;
        bool bad = 0;
        while(t <= n){
            if(n == t){
                bad = 1;
            }
            t *= 2;
        }
*/

        rep(c3,2,3){
        cin >> n;
       // n = c3;
       // solve();
        cout << solve() << "\n";
        }



    }


    return 0;
}