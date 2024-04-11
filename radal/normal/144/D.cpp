#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e14;
const long double eps = 0.0001;
vector <pll> adj[N];
int cnt = 0;
ll d[N];
ll l;
pair<pll,ll> edge[N];
void dij(int v){
    d[v] = 0;
    set<pll> st;
    st.insert({0,v});
    while (!st.empty()){
        pll p = *(st.begin());
        int v = p.Y;
        st.erase(st.begin());
        for (pll u : adj[v]){
            if (d[u.X] > p.X+u.Y){
                st.erase({d[u.X],u.X});
                d[u.X] = u.Y+p.X;
                st.insert({d[u.X],u.X});
            }
        }
    }
    return;
}
int main(){
    int n,m,s;
    cin >> n >> m >> s;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        edge[i] = {{u,v},w};
    }
    rep(i,1,n+1) d[i] = inf;
    cin >> l;
    dij(s);
    rep(i,1,n+1){
        if (d[i] == l) cnt++;
    }
    if (!l){
        cout << 1;
        return 0;
    }
    rep(i,0,m){
        int u = edge[i].X.X , v = edge[i].X.Y,w = edge[i].Y;
        if (d[u] > d[v]) swap(u,v);
        //if (d[u] < l && (d[v] > l || (d[v] < l && d[v]+w/2 >= l) || (d[u]+w > l && w != l))) cnt++;
        int x = l-d[u];
        int y = w-l+d[v];
        if (x > 0 && x < w && d[v] + w-x >= x+d[u]){
            cnt++;
            x =  l-d[u];
        }
        if (y > 0 && y < w && y != x && y+d[u] > w-y+d[v]) cnt++;
    }
    cout << cnt;
    return 0;
}