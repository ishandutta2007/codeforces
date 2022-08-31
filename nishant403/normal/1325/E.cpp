#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e6+10;
int d[N];
bool cnt[N];
int lprime[N];
int ss[N];

void sieve()
{
   lprime[1] = lprime[0] = -1;
    
   for(int i=2;i*i<N;i++)
       if(lprime[i] == 0) for(int j=i*i;j<N;j+=i) lprime[j] = i;
       
   ss[1] = 1;    
       
   for(int i=2;i<N;i++)
       if(lprime[i] == 0) ss[i] = i;
       else if(ss[i/lprime[i]] % lprime[i] == 0) ss[i] = ss[i/lprime[i]]/lprime[i];
       else ss[i] = ss[i/lprime[i]]*lprime[i];
}

vi g[N];
int dis[N];
bitset<N> vis;
int res = 1e9;

void go(int node)
{
    if(g[node].empty()) return;
    
    memset(dis,-1,sizeof(dis));   
    vis = 0;
    
    queue<pii> q;
    q.push({node,-1});
    dis[node] = 0;
    
    while(!q.empty())
    {
        auto x = q.front(); q.pop();
        if(vis[x.F] == 1) continue;
        
        vis[x.F] = 1;
        
        for(auto z : g[x.F])
        {
            if(z == x.S) continue;
            
            if(dis[z] == -1) dis[z] = dis[x.F] + 1,q.push({z,x.F});
            else res = min(res,dis[z] + dis[x.F]);
        }
    }
}

signed main()
{
    fast;
    sieve();
    
    int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    f(i,n) if(ss[a[i]] ==1)
    {
        cout << 1;
        return 0;
    }
    
    f(i,n)
    {
        if(lprime[ss[a[i]]] == 0) 
        {
            g[1].pb(ss[a[i]]);
            g[ss[a[i]]].pb(1);
            
            if(cnt[ss[a[i]]] == 0) cnt[ss[a[i]]] = 1;
            else 
            {
                cout << 2;
                return 0;
            }
        }
        else
        {
            int x = lprime[a[i]];
            int y = a[i]/x;
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    
    
    
   for(int i=1;i<=1000;i++) go(i);
        
   if(res == 1e9) res = -2;
    
   cout << res+1;
}