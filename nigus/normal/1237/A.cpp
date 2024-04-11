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

const int MAXN = 300001;

ll B[MAXN] = {0};
vl A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    ll np = 0;
    ll pp = 0;

    rep(c1,0,n){
        cin >> a;
        if(abs(a) % 2 == 0){
            B[c1] = a/2;
        }
        else{

            if(a < 0){
                b = -a;
                if(np == 0){
                    B[c1] = -(b/2);
                }
                else{
                    B[c1] = -((b+1)/2);
                }
                np ^= 1;
            }
            else{
                if(pp == 0){
                    B[c1] = a/2;
                }
                else{
                    B[c1] = (a+1)/2;
                }
                pp ^= 1;
            }

        }
    }
    a = 0;
    rep(c1,0,n){
        cout << B[c1] << "\n";
        a += B[c1];
    }

   // cerr << a << "\n";

    return 0;
}