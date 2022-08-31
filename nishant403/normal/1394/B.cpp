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

const int N = 10;
const int NN = 2e5 + 10;

int mp[N][N];
int cond[N][N];
int forbid[N][N];

vector<pii> g[NN];
int mask[NN];
int seq[NN];
int res = 0;

int n,m,k;

void fun(int nn,int msk)
{
    if(nn == k + 1)
    {
        f(i,k) if(cond[i][seq[i]] & msk) return;
        
        res++;
        
        return;
    }
    
    f(j,nn)
    {
        if(forbid[nn][j]) continue;
        
        seq[nn] = j;
        fun(nn + 1 , msk | mp[nn][j]);
    }
}

void solve()
{
   cin >> n >> m >> k;
  
   int id = 0;
    
   f(i,k) f(j,i)
   {
       mp[i][j] = (1LL<<id);
       id++;
   }
    
   int u,v,w;
    
   f(i,m)
   {
       cin >> u >> v >> w;
       g[u].pb({w,v});
   }
    
   f(i,n)
   {
       sort(all(g[i]));
       
       for(int j=0;j<g[i].size();j++)
       {
           //if already set : forbid
           if(mask[g[i][j].S] & mp[(int)g[i].size()][j + 1])
               forbid[(int)g[i].size()][j + 1] = 1;
           
           mask[g[i][j].S] |= mp[(int)g[i].size()][j + 1];
       }
   }
    
   f(i,n) f(j,k) f(v,j)
      if(mask[i] & mp[j][v])
        cond[j][v] |= mask[i];
       
   f(i,k) f(v,i)
      if(cond[i][v] & mp[i][v]) cond[i][v] ^= mp[i][v];
    
   fun(1,0);
   
   cout << res; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}