#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=2e5+30,mod = 1e9+7,inf=1e18;
ll val[N]; int par[N]; ll sum[N];
pair<ll,ll> child[N];
vector <vector<int> > adj;
ll m=-inf,m2 = -inf;
ll dfs(int v,int pa){
    par[v] = pa;
    for (ll u : adj[v]){
        if (u != pa){
            sum[v] += dfs(u,v);
        }
    }
    sum[v] += val[v];
    if (sum[v] >= m) m2 =m;
    if (sum[v] < m) m2 = max(m2,sum[v]);
    m = max(m,sum[v]);
    return sum[v];
}

void dfs2(int v,int pa){
    ll mx=sum[v];
    for (int u : adj[v]){
        if (u != pa){
            dfs2(u,v);
            mx = max(mx,sum[u]);
            if (sum[u] >= child[v].Y){
                child[v].X = child[v].Y;
                child[v].Y = sum[u];
            }
            else{
                if (sum[u] > child[v].X) child[v].X = sum[u];
            }
        }
    }
    sum[v] = mx;
}

int main(){
//    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; 
    bool f = 1,f2=0;
    cin >> n;
    rep(i,0,n){
        scanf("%lld",&val[i]);
    }
    adj.resize(n);
    rep (i,0,n-1){
        int x,y;
        scanf("%i",&x); scanf("%i",&y);
        if (max(x,y) == 2 && min(x,y) == 1) f2=1;
        x--;
        y--;
        if (y != 0) adj[x].pb(y);
        if (x != 0) adj[y].pb(x);
        if (f2 && min(x,y) == 1){
            if (x == 1){
                adj[y].pop_back();
            }
            else{
                adj[x].pop_back();
            }
        }
        if (f && (adj[x].size() >= 3 || adj[y].size() >= 3)) f=0;
    }
    if (n <= 2 || (adj[0].size() == 1 && f)){
        cout << "Impossible";
        return 0;
    }
    dfs(0,-1);
    rep (i,0,n) child[i].X=-inf,child[i].Y = -inf;
    dfs2(0,-1);
    ll ans = -inf;
    rep (i,1,n){
        if ((m + sum[i] <= ans) || (m == sum[i] && m2 + sum[i] <= ans))continue;
        if (sum[i] == child[par[i]].Y){
            ans = max(ans,sum[i] + child[par[i]].X);
        }
        else{
            ans = max(ans,child[par[i]].Y + sum[i]);
        }
    }
    cout << ans << endl;
    return 0;
}