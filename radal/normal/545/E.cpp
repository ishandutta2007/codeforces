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
const long long int N=3e5+20,mod = 1e9+7,inf=2e14;
const long double eps = 0.0001;
vector <pair<pll,ll> > adj[N];
ll d[N];
pair<pll,ll> par[N];
pair<pll,ll> edge[N];
void dij(int v){
    d[v] = 0;
    set<pair<pll,ll> > st;
    st.insert({{0,0},v});
    par[v] = {{-1,0},-1};
    while (!st.empty()){
        pair<pll,ll> p = *(st.begin());
        ll v = p.Y;
        st.erase(st.begin());
        for (auto u : adj[v]){
            if (d[u.X.X] > p.X.X+u.X.Y){
                st.erase({{d[u.X.X],par[u.X.X].X.Y},u.X.X});
                d[u.X.X] = u.X.Y+p.X.X;
                par[u.X.X].X.Y = u.X.Y;
                st.insert({{d[u.X.X],par[u.X.X].X.Y},u.X.X});
                par[u.X.X].X.X = v;
                par[u.X.X].Y = u.Y;
            }
            else if (d[u.X.X] == p.X.X+u.X.Y && par[u.X.X].X.Y > u.X.Y){
                st.erase({{d[u.X.X],par[u.X.X].X.Y},u.X.X});
                par[u.X.X].X.Y = u.X.Y;
                par[u.X.X].X.X = v;
                par[u.X.X].Y = u.Y;
                st.insert({{d[u.X.X],par[u.X.X].X.Y},u.X.X});
            }
        }
    }
    return;
}
int main(){
    memset(d,63,sizeof d);
    int n,m,s;
    cin >> n >> m;
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({{v,w},i+1});
        adj[v].pb({{u,w},i+1});
    }
    cin >> s;
    dij(s);
    ll sum = 0;
    rep(i,1,n+1) sum += par[i].X.Y;
    cout << sum << endl;
    rep(i,1,n+1) if (par[i].Y != -1) cout << par[i].Y << ' ';
    return 0;
}