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

const int MAXN = 2001;

ll i2 = (big+1)/2;

ll DP[MAXN][MAXN] = {0};
bool overk[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m >> k;
        m = n-m;
        rep(c1,0,m+1){
            overk[0][c1] = 0;
            DP[0][c1] = 0;
        }
        rep(i, 1, n+1){
            rep(sub, 0, m+1){
                if(sub == 0){
                    DP[i][sub] = DP[i-1][sub] + k;
                    overk[i][sub] = 1;
                }
                else{
                    if(overk[i-1][sub-1] && 0){
                        DP[i][sub] = DP[i-1][sub] + k;
                        overk[i][sub] = 1;
                    }
                    else{
                        DP[i][sub] = i2 * (DP[i-1][sub] + DP[i-1][sub-1]);
                        overk[i][sub] = 0;
                    }
                }
                DP[i][sub] %= big;
            }
        }
        cout << DP[n][m] << "\n";
    }


    return 0;
}