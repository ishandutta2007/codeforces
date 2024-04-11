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

const int MAXN = 401;

vector<vi> C(MAXN, vi());

int dist[MAXN][MAXN] = {0};
vector<vi> ORDER(MAXN, vi());
int par[MAXN][MAXN] = {0};
bool mark[MAXN] = {0};
bool UNIQUE[MAXN][MAXN] = {0};

void bfs(int start){
    queue<int> Q;
    Q.push(start);
    rep(c1,0,n){
        dist[start][c1] = -1;
        par[start][c1] = -1;
        mark[c1] = 0;
        UNIQUE[start][c1] = 1;
    }
    dist[start][start] = 0;
    while(!Q.empty()){
        int i = Q.front();
        Q.pop();
        if(!mark[i]){
            mark[i] = 1;
            ORDER[start].push_back(i);
            rep(c1,0,sz(C[i])){
                int j = C[i][c1];
                if(dist[start][j] == -1){
                    dist[start][j] = 1 + dist[start][i];
                    par[start][j] = i;
                    Q.push(j);
                }
                else{
                    if(dist[start][j] == 1 + dist[start][i]){
                        UNIQUE[start][j] = 0;
                    }
                }
            }
        }
    }
}

int CCC[MAXN] = {0};
int cc = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        a--;b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    rep(c1,0,n){
        bfs(c1);
    }

    rep(c1,0,n){
        rep(c2,0,n){
            if(!UNIQUE[c1][c2]){
                cout << "0 ";
            }
            else{
                cc++;
                int j = c2;
                while(j != -1){
                    CCC[j] = cc;
                    j = par[c1][j];
                }
                ll ans = 1;
                rep(c3,0,n){
                    int i = ORDER[c1][c3];
                    if(CCC[i] != cc){
                        ll temp = 0;
                        trav(j, C[i]){
                            if(CCC[j] == cc && dist[c1][i] == dist[c1][j]+1 && dist[c2][i] == dist[c2][j]+1){
                                temp++;
                            }
                        }
                        CCC[i] = cc;
                        ans *= temp;
                        ans %= mod;

                    }
                }
                cout << ans << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}