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

typedef unsigned long long int ll;
typedef pair<int,int> pll;
const long long int N=1e5+30,mod = 1e9+7,inf=1e9;
vector <int> adj[N];
pair<pll,int> edge[N];
ll child[N],par[N];
int dfs(int v,int p){
    par[v] = p;
    for(int u : adj[v]){
        if (u != p) child[v] += dfs(u,v);
    }
    child[v]++;
    return child[v];
    
}
int main(){
    ll n,q;
    ll ans = 0;
    cin >> n;
    rep (i,1,n){
        cin >> edge[i].X.X >> edge[i].X.Y >> edge[i].Y;
        adj[edge[i].X.X].pb(edge[i].X.Y);
        adj[edge[i].X.Y].pb(edge[i].X.X);
    }
    dfs(1,-1);
    rep(i,1,n){
        int u = edge[i].X.X;
        int v = edge[i].X.Y;
        if (u == par[v]) swap(u,v);
        ans += child[u]*(n-child[u])*edge[i].Y;
    //    debug(ans);
    }
    cin >> q;
    rep (i,0,q){
        int ind , val;
        long double out;
        cin >> ind >> val;
        int u = edge[ind].X.X;
        int v = edge[ind].X.Y;
        if (u == par[v]) swap(u,v);
        ans-=(edge[ind].Y-val)*child[u]*(n-child[u]);
        edge[ind].Y= val;
        out = ans*6;
        out /= (n*(n-1));
        cout << setprecision(9) <<out << endl;
    }
}