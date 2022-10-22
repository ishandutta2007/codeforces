
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

const int MAXN = 1000001;

vector<vi> grid(MAXN, vi());
vector<vi> dist(MAXN, vi());
vector<vi> mark(MAXN, vi());

vector<vi> DP(MAXN, vi());

vector<vi> dist2(MAXN, vi());

int DX[8] = {1,1,0,-1,-1,-1,0,1};
int DY[8] = {0,1,1,1,0,-1,-1,-1};

bool inbounds(ll i, ll j){
    return i>=0 && j>=0 && i<n && j<m;
}

bool on_edge(ll i, ll j){
    if(!inbounds(i,j) || grid[i][j] == 0)return 1;
    rep(c1,0,8){
        ll i2 = i+DX[c1];
        ll j2 = j+DY[c1];
        if(!inbounds(i2,j2) || grid[i2][j2] == 0)return 1;
    }
    return 0;
}

ll tot_fire = 0;

void bfs1(){
    queue<pii> Q;
    rep(c1,0,n){
        rep(c2,0,m){
            if(grid[c1][c2] == 1){
                if(on_edge(c1,c2)){
                    Q.push({c1,c2});
                    dist[c1][c2] = 0;
                }
            }
        }
    }
    while(!Q.empty()){
        ll i = Q.front().first;
        ll j = Q.front().second;
        Q.pop();
        if(!mark[i][j]){
            mark[i][j] = 1;
            tot_fire++;
            for(int c1 = 0; c1 < 8; c1++){
                ll i2 = i+DX[c1];
                ll j2 = j+DY[c1];
                if(inbounds(i2,j2) && grid[i2][j2] == 1 && dist[i2][j2] == -1){
                    dist[i2][j2] = dist[i][j]+1;
                    Q.push({i2,j2});
                }
            }
        }
    }
}

bool bfs2(ll d){
    queue<pii> Q;
    ll on_fire = 0;

    rep(c1,0,n){
        rep(c2,0,m){
            mark[c1][c2] = 0;
            dist2[c1][c2] = -1;
            if(grid[c1][c2] == 1){
                if(dist[c1][c2] >= d){
                    Q.push({c1,c2});
                    dist2[c1][c2] = 0;

                }
            }
        }
    }

    while(!Q.empty()){
        ll i = Q.front().first;
        ll j = Q.front().second;
        Q.pop();
        if(!mark[i][j]){
            mark[i][j] = 1;
            on_fire++;
            if(dist2[i][j] >= d)continue;
            for(int c1 = 0; c1 < 8; c1++){
                ll i2 = i+DX[c1];
                ll j2 = j+DY[c1];
                if(inbounds(i2,j2) && grid[i2][j2] == 1 && dist2[i2][j2] == -1){
                    dist2[i2][j2] = dist2[i][j]+1;
                    Q.push({i2,j2});
                }
            }
        }
    }
    return (on_fire == tot_fire);
}

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
            grid[c1].push_back((s[c2] == 'X'));
            dist[c1].push_back(-1);
            mark[c1].push_back(0);
            DP[c1].push_back(-1);
            dist2[c1].push_back(-1);
        }
    }
    bfs1();

    ll l = 0;
    ll r = (n+m);

    while(l < r-1){
        ll mid = (l+r)/2;
        bool res = bfs2(mid);
        if(res){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    //bs

    cout << l << "\n";
    rep(c1,0,n){
        rep(c2,0,m){
            if(grid[c1][c2] == 0){
                cout << ".";
            }
            else{
                if(dist[c1][c2] < l){
                    cout << ".";
                }
                else{
                    cout << "X";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}