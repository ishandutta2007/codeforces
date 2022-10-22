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

const int MAXN = 300001;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> T;
    rep(c1,0,T){
        cin >> n;
        vi A(n);
        int F[101] = {0};
        rep(c2,0,n){
            cin >> a;
            F[a]++;
        }
        ll ans = 0;
        rep(c1,0,101){
            if(F[c1] < 2){
                ans += c1;
                break;
            }
        }
        rep(c1,0,101){
            if(F[c1] < 1){
                ans += c1;
                break;
            }
        }
        cout << ans << "\n";

    }

    /*
    cin >> T;
    rep(c4,0,T){


        //cerr << "Case #" << c4+1 << ": " << prod  << "\n";
        cout << "Case #" << c4+1 << ": " << ans << "\n";

    }
*/
    return 0;
}