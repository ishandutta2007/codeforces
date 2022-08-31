#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5+10;

vi g[N];
vi res(N,-1);
int n;
map<pii,int> mp;

void solve()
{
    cin >> n;
    
    if(n<=3)
    {
        f(i,n-1) cout << i << '\n';
        return;
    }
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        mp[{u,v}] = i;
        mp[{v,u}] = i;
    }
    
    int flag = 0;
    
    for(int i=1;i<=n;i++)
        if(g[i].size() >= 3)
    {
        f(j,3) res[mp[{i,g[i][j]}]] = flag++;
        break;
    }
    
    f(i,n-1) if(res[i] == -1) res[i] = flag++;
    f(i,n-1) cout << res[i] << '\n';
}

signed main()
{
    fast;
    
    solve();
}