#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 5004;
unordered_map<int,int> g[N];
int par[N];
int dep[N];
vi num[N];

void solve()
{
   int n,d;
   cin >> n >> d;
    
   int mn = 0;
   int mx = (n*(n-1))/2;   
    
   int lev = 0;
   int nodes = n;
   int sub = 1;
    
   while(nodes > 0)
   {
       mn+=(lev*min(sub,nodes));
       nodes-=min(nodes,sub);
       sub<<=1;
       lev++;
   }
    
   if(d < mn || d > mx)
   {
       cout << "NO\n"; return;
   }
    
   for(int i=1;i<=n;i++) g[i].clear();
   for(int i=1;i<=n;i++) num[i].clear();
   
   dep[1] = 0; 
   num[0].pb(1); 
   par[1] = -1; 
    
   int run = 0; 
   
   for(int i=2;i<=n;i++)
   {
     g[i][i/2] = 1;
     g[i/2][i] = 1;
     par[i] = i/2;
     dep[i] = dep[i/2] + 1;
     run+=dep[i];
     num[dep[i]].pb(i);
   }
    
   while(run < d)
   {
     for(int i=n;i>=0;i--)
     {
         if(num[i].size() > 1)
         {
             auto x = num[i].back();
             num[i].pop_back();
             num[i+1].pb(x);
             
             int pp = par[x];
       
             g[pp].erase(x);
             g[x].erase(pp);
             
             int np = -1;
             
             for(auto z : num[i])
             {
                 if(g[z].size() <=2 )
             {
                 np = z;
                 break;
             }
                 
             }
             
             
             g[np][x] = 1;
             g[x][np] = 1;
             run++;
             
             par[x] = np;
             
             break;
         }
     }
   }
       
   cout <<"YES\n";
   for(int i=2;i<=n;i++) cout << par[i]<<" ";
   cout << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
 
    cin >> t;
    
    while(t--)
        
    solve();
}