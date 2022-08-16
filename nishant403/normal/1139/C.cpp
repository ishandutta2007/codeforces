#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=1;i<=n;i++)
#define pb push_back
#define pll pair<ll,ll>
#define vll vector<ll> 

ll M = 1000000007;

vector<bool> vis(100001,false);
vll adj[100001];
   

ll pow(ll a,ll b)
{
 ll an=1;

    while(b)
    {
     if(b&1) an=(an*a)%M;
     a=(a*a)%M;
     b>>=1;   
    }
    return an;
}

ll dfs(ll x)
{
 ll an=1;
 vis[x]=1;  
    
   for(auto i : adj[x]) 
       if(!vis[i]) an+=dfs(i);
    
   return an; 
}

int main()
{
 fast;   
 ll n,k,i,j,a=0,x,y,z;
 string s;
    
 cin >> n >> k;   
     
  f(i,n-1)
  {
   cin >> x >> y >> z;   
   if(z==0) adj[x].pb(y),adj[y].pb(x);   
  }
    
   f(i,n)
   {
    if(vis[i]) continue;   
    a=(a+pow(dfs(i),k))%M;
   }
 
 a=((pow(n,k)-a)%M + M )%M;
    
   cout << a; 
}