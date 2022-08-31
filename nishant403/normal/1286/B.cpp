#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e3+10;
vi g[N];
int sz[N];
int c[N];
int go[N][N];

void dfs(int node)
{
    int val = 1;
    
    for(auto x : g[node])
    {
        dfs(x);
        f(i,N) if(go[x][i] != 0) go[node][val++] = go[x][i];
        sz[node]+=sz[x];
    }
    
    if(sz[node] < c[node])
    {
        cout <<"NO\n";
        exit(0);
    }
    
    //now magic happens
    for(int i=N-1;i>=c[node]+2;i--) go[node][i] = go[node][i-1];
    go[node][c[node]+1] = node;
    sz[node]++;
    
}

void solve()
{
    int n;
    cin >> n;
    
    int x,root = -1;
    
    f(i,n)
    {
       cin >> x >> c[i];    
       if(x == 0) root = i;
       else g[x].pb(i);
    }
    
    dfs(root);
    
    int ans[N];
    
    for(int i=1;i<N;i++) if(go[root][i] != 0)
                         ans[go[root][i]] = i;
        
    cout <<"YES\n";   
    f(i,n) cout << ans[i] <<" ";
}

signed main()
{
    fast;
    solve();
}