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

const int MAXN = 100001;

ll TWO[62] = {0};

bool get_bit(ll x, ll i){
    return (x & (1ll << i)) != 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;

    ll t = 1;
    rep(c1,0,62){
        TWO[c1] = t;
        t *= 2;
        t %= big;
    }

    rep(c4,0,T){
        ll F[62] = {0};
        cin >> n;
        vl X;
        rep(c1,0,n){
            cin >> a;
            rep(c2,0,62){
                if(get_bit(a, c2))F[c2]++;
            }
            X.push_back(a);
        }
        ll ans = 0;
        rep(c1,0,n){
            ll och = 0;
            ll eller = 0;
            rep(c2,0,62){
                bool bit = get_bit(X[c1], c2);
                if(bit){
                    och += F[c2] * TWO[c2];
                }

                if(bit){
                    eller += n * TWO[c2];
                }
                else{
                    eller += F[c2] * TWO[c2];
                }
                och %= big;
                eller %= big;
            }
            ans += och*eller;
            ans %= big;
        }
        cout << ans << "\n";
    }

    return 0;
}