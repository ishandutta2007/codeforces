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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1001;

bool inbounds(ll i, ll j){
    return i >= 0 && j  >= 0 && i < n && j < m;
}

int DX[4] = {0,0,1,-1};
int DY[4] = {1,-1,0,0};

int grid[MAXN][MAXN] = {0};
ll frozen[MAXN][MAXN] = {0};
bool mark[MAXN][MAXN] = {0};

void bfs(){
    queue<int> Q;
    rep(c1,0,n){
        rep(c2,0,m){
            frozen[c1][c2] = big*big;
            rep(c3,0,4){
                int i = c1+DX[c3];
                int j = c2+DY[c3];
                if(inbounds(i,j) && grid[i][j] == grid[c1][c2]){
                    frozen[c1][c2] = 0;
                    Q.push(c1*m+c2);
                }
            }
        }
    }
    while(!Q.empty()){
        int i = Q.front();
        Q.pop();
        int x = i/m;
        int y = i%m;
        if(!mark[x][y]){
            mark[x][y] = 1;
            rep(c1,0,4){
                int x2 = x + DX[c1];
                int y2 = y + DY[c1];
                if(inbounds(x2,y2) && frozen[x2][y2] == big*big){
                    frozen[x2][y2] = frozen[x][y]+1;
                    Q.push(x2*m+y2);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m >> q;
    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            grid[c1][c2] = (s[c2]-'0');
        }
    }
    bfs();
    rep(c1,0,q){
        cin >> a >> b >> c;
        a--;
        b--;
        if(c <= frozen[a][b]){
            cout << grid[a][b] << "\n";
        }
        else{
            cout << (grid[a][b] + (c - frozen[a][b]))%2 << "\n";
        }
    }

    return 0;
}