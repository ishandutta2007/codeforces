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
#define all(x) x.begin(),x.end()

const int MOD = 998244353;
const int N = 405;

vi g[N];
int dis[N][N];

signed main()
{
    fast;
    
    int n,m;
    cin >> n >> m;
    
    int u,v;
    
    f(i,m)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    f(i,n)
    {
        f(j,n) dis[i][j] = N;
        
        queue<pii> q;
        q.push({i,0});
        
        while(!q.empty())
        {
            auto x = q.front(); q.pop();
            
            if(dis[i][x.F] <= x.S) continue;
            dis[i][x.F] = x.S;
            
            for(auto z : g[x.F])
                if(dis[i][z] > x.S + 1) q.push({z,x.S + 1});
        }
    }
    
    f(i,n)
    {
        f(j,n)
        {
            int ans = 1;    
           
            int mid = 0;
            f(k,n) if(dis[i][k] + dis[k][j] == dis[i][j]) mid++;
            if(mid > dis[i][j] + 1) ans = 0;
            
            f(k,n) if(dis[i][k] + dis[k][j] != dis[i][j])
            {
                int temp = 0;
                
                for(auto x : g[k])
                  temp += (dis[x][i] == dis[k][i] - 1 && dis[x][j] == dis[k][j] - 1);
                
                ans = (ans*temp)%MOD;
            }
            
            cout << ans << ' ';
        }
        
        cout << '\n';
    }
}