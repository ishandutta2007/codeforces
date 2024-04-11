#pragma GCC optimize("O3")
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

const ll MAXN = 504;

int grid[MAXN][MAXN] = {0};
bool moved[MAXN][MAXN] = {0};
int P[MAXN] = {0};

vector<pii> tried;

bool f(ll i, ll j){
    for(int c1 = i-1; c1 < n; c1++){
        if(grid[c1][j-1] == 1)return 0;
    }
    for(int c1 = j-1; c1 < m; c1++){
        if(grid[i-1][c1] == 1)return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            grid[c1][c2] = (s[c2] == 'B');
        }
    }

    int ans = 0;

    vi last_row;
    vi last_col;

    bool bonus = 0;

    for(int c1 = n-1; c1 >= 0; c1--){
        int sum = 0;
        for(int c2 = m-1; c2 >= 0; c2--){
            sum += P[c2];
            if(grid[c1][c2] != sum%2){
                P[c2]++;
                sum++;
                ans++;
                moved[c1][c2] = 1;

                if(c1 != n-1 && c2 != m-1){
                    if(moved[c1][m-1] && moved[n-1][c2] && moved[n-1][m-1])bonus = 1;

                }

                if(c1 == n-1)last_row.push_back(c2);
                if(c2 == m-1)last_col.push_back(c1);
            }
        }
    }

    /*
    if(grid[n-1][m-1] == 1 && sz(last_row) >= 2 && sz(last_col) >= 2){
        int ans2 = 0;

        for(int c1 = 0; c1 < m; c1++){
            P[c1] = 0;
        }

        for(int c1 = n-1; c1 >= 0; c1--){
            int sum = 0;
            for(int c2 = m-1; c2 >= 0; c2--){
                sum += P[c2];
                int g = grid[c1][c2];
                if(c1 <= last_col[1] && c2 == last_row[1]){
                    sum++;
                }

                if(g != sum%2){
                    P[c2]++;
                    sum++;
                    ans2++;
                }
            }
        }

        cerr << "BONUS " << ans2 << " vs " << ans << "\n";
        if(ans2 < ans){
            ans = ans2;
        }
    }*/

    /*

    int mi = m-1;

    for(int c1 = n-1; c1 >= 1; c1--){
        if(grid[c1][m-1] == 0)break;
        for(int c2 = m-1; c2 >= m-mi; c2--){
            if(grid[c1][c2-1] == 0){
                mi = m-c2;
                tried.push_back({c1, c2});
                break;
            }
        }
    }


    trav(p, tried){
        if(f(p.first, p.second)){
            ans--;
            cerr << "BONUS " << p.first << " " << p.second << "\n";
            break;
        }
    }
*/
    cout << ans-bonus << "\n";

    return 0;
}