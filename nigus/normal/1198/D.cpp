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

const ll MAXN = 51;

int A[MAXN][MAXN] = {0};
int SUM[MAXN][MAXN][MAXN][MAXN] = {0};
void setup(){
    rep(c1,0,n){
        rep(c2,0,n){
            rep(c3,c1,n){
                rep(c4,c2,n){
                    if(c1 == c3 && c2 == c4){
                        SUM[c1][c2][c3][c4] = A[c1][c2];
                    }
                    else{
                        if(c1 == c3){
                            SUM[c1][c2][c3][c4] = SUM[c1][c2][c3][c4-1] + A[c3][c4];
                        }
                        if(c2 == c4){
                            SUM[c1][c2][c3][c4] = SUM[c1][c2][c3-1][c4] + A[c3][c4];
                        }
                        if(c1 != c3 && c2 != c4){
                            SUM[c1][c2][c3][c4] = SUM[c1][c2][c3][c4-1] + SUM[c1][c2][c3-1][c4] - SUM[c1][c2][c3-1][c4-1] + A[c3][c4];
                        }
                    }
                }
            }
        }
    }
}

int DP[MAXN][MAXN][MAXN][MAXN] = {0};
bool DPC[MAXN][MAXN][MAXN][MAXN] = {0};

int dp(int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y2)return 0;
    if(x1 == x2 && y1 == y2)return A[x1][y1];
    if(DPC[x1][y1][x2][y2])return DP[x1][y1][x2][y2];
    int ans = max(y2-y1+1, x2-x1+1);
    rep(c1,x1,x2+1){
        if(SUM[c1][y1][c1][y2] == 0){
            int temp = dp(x1,y1,c1-1,y2) + dp(c1+1,y1,x2,y2);
            ans = min(ans, temp);
        }
    }
    rep(c1,y1,y2+1){
        if(SUM[x1][c1][x2][c1] == 0){
            int temp = dp(x1,y1,x2,c1-1) + dp(x1,c1+1,x2,y2);
            ans = min(ans, temp);
        }
    }
   DPC[x1][y1][x2][y2] = 1;
   DP[x1][y1][x2][y2] = ans;
   return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
   // n = 50;
    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,n){
            A[c1][c2] = (s[c2] == '#');
           // A[c1][c2] = (rand()%70 == 0);
        }
    }

    setup();
    int ans = dp(0,0,n-1,n-1);
    cout << ans << "\n";

    return 0;
}