#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 2e3 + 10;
const int inf = 1e18;

int n,m,w;
int a[N][N];

vector<pii> g[N*N];
vector<bool> vis(N*N,0);
vector<bool> vis2(N*N,0);
vector<int> dis(N*N,inf);
vector<int> dis2(N*N,inf);

inline int encode(int i,int j)
{
    return (i*m) + j;
}

int xx[] = {1,-1,0,0};
int yy[] = {0,0,1,-1};

bool valid(int i,int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m && a[i][j] >= 0);
}

void solve()
{
   cin >> n >> m >> w;
   f(i,n) f(j,m) cin >> a[i][j];
    
   dis[0] = 0;
   queue<pii> PQ;
   PQ.push({0,0}); 
  
   while(!PQ.empty())
   {
       auto x = PQ.front();  PQ.pop();
       
       if(vis[x.S] == 1) continue;
       vis[x.S] = 1;
      
       int i = (x.S / m);
       int j = (x.S % m);
       
       f(v,4)
       {
           if(valid(i+xx[v],j+yy[v]))
           {
               pii z = {encode(i + xx[v],j + yy[v]),w};
               
               if(dis[z.F] > dis[x.S] + z.S)
               {
                   dis[z.F] = dis[x.S] + z.S;
                   PQ.push({dis[z.F],z.F});
               }
           }
       }
   }  
    
   dis2[(n*m) - 1] = 0;
   PQ.push({0,(n*m)-1}); 
  
   while(!PQ.empty())
   {
       auto x = PQ.front();  PQ.pop();
       
       if(vis2[x.S] == 1) continue;
       vis2[x.S] = 1;
      
       int i = (x.S / m);
       int j = (x.S % m);
       
       f(v,4)
       {
           if(valid(i+xx[v],j+yy[v]))
           {
               pii z = {encode(i + xx[v],j + yy[v]),w};
               
               if(dis2[z.F] > dis2[x.S] + z.S)
               {
                   dis2[z.F] = dis2[x.S] + z.S;
                   PQ.push({dis2[z.F],z.F});
               }
           }
       }
   }  
    
   int res = dis2[0]; 
   int m1 = inf;
    
   //use atmost one portal
   f(i,n) f(j,m)
   {
       if(a[i][j] <= 0) continue;
       m1 = min(m1 , dis[encode(i,j)] + a[i][j]);
   }
   
    f(i,n) f(j,m)
    {
       if(a[i][j] <= 0) continue;
       res = min(res , m1 + a[i][j] + dis2[encode(i,j)]);
    }
    
   if(res == inf) res = -1;
    
   cout << res; 
}

signed main()
{
    fast;
    solve();
}