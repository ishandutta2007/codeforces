#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 2e5+10;
int M = 998244353 ;

vector<int> fact(N,1);
vector<int> graph[N];

signed main()
{
    fast;
    
int n;
    cin >> n;
    
    int a,b;
   
   
   f(i,n-1)
   {
       cin >> a>> b;
       graph[a].pb(b);
       graph[b].pb(a);
     
   }
   
    
    int ans= n;
    
      
    for(int i=2;i<N;i++) fact[i] =(fact[i-1]*i)%M;
    
    
    for(int i=1;i<=n;i++)
    {
     ans=(ans*fact[graph[i].size()])%M;   
     
    }
    
    cout << ans;
        
    
    
}