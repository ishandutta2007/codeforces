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

const int N = 2e5+10;
vi g[N];

void solve()
{  
    
 int n,m;
    cin >> n >> m;
 
 int p[n+1];
    
    f(i,n) p[i+1] = i+1;
    
   p[0] = 0;  
    
 int a[m];
    f(i,m) cin >> a[i];
    
 f(i,m-1)
    {
     g[a[i]].pb(a[i+1]);
     g[a[i+1]].pb(a[i]);
    }
    
 int sum = 0;
  
 f(i,m-1) sum+=abs(p[a[i]]-p[a[i+1]]);    
    
 cout << sum << ' ';   
    
 for(int i=2;i<=n;i++)
 {
     //positions at i-1 and i are changed
     int diff = 0;
     
     //remove for i-1
     for(auto x : g[i-1]) diff-=abs(p[i-1] - p[x]);
     
     for(auto x : g[i]) if(x!=i-1) diff-=abs(p[i] - p[x]);
         
     p[i] = 1;
     p[i-1] = i;
       
     for(auto x : g[i-1])
      diff+=abs(p[i-1] - p[x]);       
     
     for(auto x : g[i]) if(x!=i-1) diff+=abs(p[i] - p[x]);
    
             
     sum+=diff;
     
     cout << sum << ' '; 
 }   
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}