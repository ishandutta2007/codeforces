#include <bits/stdc++.h>
using namespace std;
 
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N =5e6+10;

int fac[N],a,b,ans[N];

void pre()
{
    for(int i=2;i*i<N;i++)
        if(fac[i] == 0)  for(int j=i*i;j<N;j+=i) fac[j]=i; 
        
    for(int i=2;i<N;i++)
    {
      int h = i;   
        
      while(fac[h]!=0)
      {
        h/=fac[h];
        ans[i]++;  
      }
       
      ans[i]+=ans[i-1]+1; 
    }
    
}

void solve()
{
  cin >> a >> b;
  cout << ans[a]-ans[b] << "\n";
}

signed main()
{
    fast;
    
    pre();
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}