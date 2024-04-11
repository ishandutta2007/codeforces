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

const int MAXN = 403;

const int CAP = 30;

ll CS[MAXN][MAXN] = {0};
ll grid[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n >> m;
        rep(c1,0,n){
            string s;
            cin >> s;
            CS[c1][0] = 0;
            rep(c2,0,m){
                grid[c1][c2] = (s[c2] == '1');
                CS[c1][c2+1] = CS[c1][c2] + grid[c1][c2];
            }
        }

        int ans = CAP;

        rep(i1,0,n){
            rep(j1,0,m){
                int temp = 0;
                rep(j2,j1+1,m){
                    if(temp >= ans)break;
                    if(j2-j1+1 >= 4){
                        int temp2 = temp;
                        rep(i2, i1+1, n){
                            if(temp2 >= ans)break;
                            if(i2-i1+1 >= 5){
                                int temp3 = temp2 + ((j2-j1-1) - (CS[i2][j2]-CS[i2][j1+1]));
                                ans = min(ans, temp3);
                              //  cerr << i1 << " " << j1 << "  -  " << i2 << " " << j2 << "   ,,,  " << temp2 << "\n";
                            }
                            temp2 += 2 - (grid[i2][j1] + grid[i2][j2]) + CS[i2][j2] - CS[i2][j1+1];
                        }
                    }
                    temp += 1-grid[i1][j2];
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}