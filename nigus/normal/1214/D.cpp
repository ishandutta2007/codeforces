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

const ll MAXN = 1000001;

ll R1,R2;

bool ways[MAXN][2] = {0};
bool blocked[MAXN] = {0};

ll SUM[2*MAXN] = {0};


ll way(ll i, ll j, ll r){
    return ways[i*m+j][r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    R1 = random2();
    R2 = random2();

    cin >> n >> m;
    rep(c1,0,n){
        string s;
        cin >> s;

        /*
        s = "";
        rep(c2,0,m){
            s += '.';
        }
*/
        rep(c2,0,m){
            if(s[c2] == '#')blocked[c1*m+c2] = 1;
        }
    }

    for(int c1 = n-1; c1 >= 0; c1--){
        for(int c2 = m-1; c2 >= 0; c2--){

            if(blocked[c1*m+c2])continue;

            if(c1 == n-1 && c2 == m-1){
                ways[c1*m+c2][0] = 1;
            }
            else{
                if(c1 < n-1){
                    ways[c1*m+c2][0] |= way(c1+1,c2,0);
                }
                if(c2 < m-1){
                    ways[c1*m+c2][0] |= way(c1,c2+1,0);
                }

            }

        }
    }

    rep(c1,0,n){
        rep(c2,0,m){
            if(blocked[c1*m+c2])continue;

            if(c1 == 0 && c2 == 0){
                ways[c1*m+c2][1] = 1;
            }
            else{
                if(c1 > 0){
                    ways[c1*m+c2][1] |= way(c1-1,c2,1);
                }
                if(c2 > 0){
                    ways[c1*m+c2][1] |= way(c1,c2-1,1);
                }

            }
            SUM[(c1+c2)] += (way(c1,c2,0)&way(c1,c2,1));

        }
    }

    ll ans = 2;
    if(way(0,0,0) == 0){
        cout << "0\n";
        return 0;
    }

    rep(c1,0,n){
        rep(c2,0,m){

            //cerr << way(c1,c2,1) << " ";

            if((c1 == 0 && c2 == 0) || (c1 == n-1 && c2 == m-1))continue;
            if(SUM[(c1+c2)] == 1)ans = 1;
        }//cerr << "\n";
    }

    cout << ans << "\n";


    return 0;
}