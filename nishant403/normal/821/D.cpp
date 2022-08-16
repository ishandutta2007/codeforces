#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 1e5 + 10;
const int inf = N;

vector<pii> g[N];
pii a[N];

map<pii,int> mp;

int n,m,k;
int xx[] = {1,-1,0,0};
int yy[] = {0,0,1,-1};

bool valid(int x,int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m && mp.find({x,y}) != mp.end());
}

int dis[N];

int get_id(int x,int y)
{
    if(mp.find({x,y}) == mp.end()) 
    {
        int sz = (int)mp.size() + 1;
        mp[{x,y}] = sz;
    }
    
    return mp[{x,y}];
}

void solve()
{
   cin >> n >> m >> k;
   
   for(int i=1;i<=k;i++) cin >> a[i].F >> a[i].S;
   
   for(int i=1;i<=k;i++) a[i].F--,a[i].S--;
   for(int i=1;i<=k;i++) mp[a[i]] = i; 
   
   for(int i=1;i<=k;i++)
   {
       for(int x=-1;x<=1;x++)
           for(int y=-1;y<=1;y++)
           {
               int dd = abs(x) + abs(y);

               if(dd != 1) continue;

               if(valid(a[i].F + x,a[i].S + y))
                   g[i].pb({0,get_id(a[i].F + x,a[i].S + y)});
           }
       
       for(int x=-1;x<=1;x++)
       {
           if(a[i].F + x < 0 || a[i].F + x >= n) continue;
           g[i].pb({1,k + a[i].F + x + 1});
           g[k + a[i].F + x + 1].pb({0,i});
       }
       
       for(int y=-1;y<=1;y++)
       {
           if(a[i].S + y < 0 || a[i].S + y >= m) continue;
           g[i].pb({1,k + a[i].S + y + 1 + n});
           g[k + a[i].S + y + 1 + n].pb({0,i});
       }
   }
    
   int source = get_id(0,0);
    
   int dest = -1;    
    
   //create cell for (n-1,m-1) if it doesn't exists and add appropriate edges
   if(!valid(n-1,m-1))
   {
       mp[{n-1,m-1}] = N - 1;
       
       dest = get_id(n-1,m-1);
       
       for(int i=1;i<=k;i++)
       {
           int dd = abs(a[i].F - (n-1)) + abs(a[i].S - (m-1));
           if(dd == 1) g[i].pb({1,dest});
       }
       
       g[k + n].pb({0,dest});
       g[k + n + m].pb({0,dest});
   }
   else dest = get_id(n-1,m-1);
    
   for(int i=1;i<N;i++) dis[i] = inf;
 
   priority_queue<pii,vector<pii> ,greater<pii> > pq;
   pq.push({0,source});
   
   while(!pq.empty())
   {
       auto z = pq.top();  pq.pop();
       
       if(dis[z.S] <= z.F) continue;
       dis[z.S] = z.F;
       
       for(auto v : g[z.S])
           if(dis[v.S] > v.F + z.F)
               pq.push({v.F + z.F , v.S});
   }
    
   if(dis[dest] == N) dis[dest] = -1;
    
   cout << dis[dest];
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}