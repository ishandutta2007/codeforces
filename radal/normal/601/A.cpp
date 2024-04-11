#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long  int ll;
typedef pair<ll,ll> pll;

const long long int N=4e2+30,mod = 1e9+7,inf=1e18;
const long double eps = 0.0001;
int n,m;
set <pll> st;
vector<int> adj[N];
int dist[N];
void nt(){
    rep(i,1,n){
        rep(j,i+1,n+1){
            if (st.find({i,j}) == st.end()){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
}
void bfs(){
    dist[1] = 1;
    queue <int> q;
    q.push(1);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (!dist[v]){
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    bool f = 0;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        if (x == 1 && y == n) f  = 1;
        st.insert({x,y});
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (f){
        rep(i,1,n+1) adj[i].clear();
        nt();
    }
    bfs();
    cout << dist[n]-1;
    return 0;
}