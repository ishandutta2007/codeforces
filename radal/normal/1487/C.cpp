#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e2+20,mod = 1e9+7,inf=4e18,maxk = 1e5+20;
const long double eps = 0.0001;
int b[N][N],n;
bool vis[N*N];
vector<int> ve;
vector<pll> adj[N];
void dfs(int v){
    while (!adj[v].empty()){
        pll u = adj[v].back();
        adj[v].pop_back();
        if (!vis[u.Y]){
            vis[u.Y] = 1;
            b[u.X][v] = -1;
            b[v][u.X] = 1;
            dfs(u.X);
        }
    }
    ve.pb(v);
    return;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        memset(b,0,sizeof b);
        cin >> n;
        int t = 0;
        rep(i,0,n) adj[i].clear();
        if (n%2){
            rep(i,0,n){
                rep(j,i+1,n){
                    adj[i].pb({j,t});
                    adj[j].pb({i,t});
                    vis[t] = 0;
                    t++;
                }
            }
            dfs(0);
            rep(i,0,n){
                rep(j,i+1,n){
                    cout << b[i][j] << ' ';
                }
            }
        }
        else{
            rep(i,0,n){
                rep(j,i+1,n){
                    if(j%2 && j == i+1) continue;
                    adj[j].pb({i,t});
                    adj[i].pb({j,t});
                    vis[t] = 0;
                    t++;
                }
            }
            dfs(0);
            rep(i,0,n){
                rep(j,i+1,n) cout << b[i][j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}