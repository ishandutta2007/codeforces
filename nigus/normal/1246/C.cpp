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

const int MAXN = 2001;

ll row[MAXN][MAXN] = {0};
ll col[MAXN][MAXN] = {0};
bool grid[MAXN][MAXN] = {0};

ll DP[MAXN][MAXN][2] = {0};
ll DPF[MAXN][MAXN][2] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;

    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            grid[c1][c2] = (s[c2] == 'R');
           // grid[c1][c2] = 0;
        }
    }


    if(grid[n-1][m-1] == 1){
        cout << "0\n";
        return 0;
    }

    if(n == 1 && m == 1){
        cout << "1\n";
        return 0;
    }

    for(int c1 = n-1; c1 >= 0; c1--){
        for(int c2 = m-1; c2 >= 0; c2--){
            if(c1 == n-1){
                col[c2][c1] = 0;
            }
            else{
                col[c2][c1] = (grid[c1+1][c2] == 0) + col[c2][c1+1];
            }

            if(c2 == m-1){
                row[c1][c2] = 0;
            }
            else{
                row[c1][c2] = (grid[c1][c2+1] == 0) + row[c1][c2+1];
             //   cerr << grid[c1][c2+1] << "," << row[c1][c2+1] << "  ";
            }
        }//cerr << "\n";
    }

/*
    rep(c1,0,n){
        rep(c2,0,m){
            cerr << row[c1][c2] << " ";
        }
        cerr << "\n";
    }
*/

    for(int c1 = n-1; c1 >= 0; c1--){
        for(int c2 = m-1; c2 >= 0; c2--){
            if(c2 == m-1){
                DP[c1][c2][0] = (col[c2][c1] == n-1-c1);
            }
            else{
                DP[c1][c2][0] = DPF[c2][c1+1][1] - DPF[c2][c1+1+col[c2][c1]][1];

                DP[c1][c2][0] += 2*big;
                DP[c1][c2][0] %= big;
            }

            if(c1 == n-1){
                DP[c1][c2][1] = (row[c1][c2] == m-1-c2);
            }
            else{
                DP[c1][c2][1] = DPF[c1][c2+1][0] - DPF[c1][c2+1+row[c1][c2]][0];

                DP[c1][c2][1] += 2*big;
                DP[c1][c2][1] %= big;
            }

            DPF[c1][c2][0] = (DPF[c1][c2+1][0] + DP[c1][c2][0]) % big;
            DPF[c2][c1][1] = (DPF[c2][c1+1][1] + DP[c1][c2][1]) % big;

        }
    }

    cout << (DP[0][0][0] + DP[0][0][1])%big << "\n";

    return 0;
}