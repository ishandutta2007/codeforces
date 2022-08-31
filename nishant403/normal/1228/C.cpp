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

const int M = 1e9+7; 

bool isOverflow(long long a, long long b) 
{ 
    // Check if either of them is zero 
    if (a == 0 || b == 0)  
        return false; 
      
    long long result = a * b; 
    if (a == result / b) 
        return false; 
    else
        return true; 
} 

int pw(int a,int b)
{
 int res = 1;
  
 b%=(M-1);
 a%=M;
    
    while(b)
    {
     if(b&1) res=(res*a)%M;
     a=(a*a)%M;
     b>>=1;
    }
    
   return res; 
}

vi fact(int x)
{
  vi temp;
    
    for(int i=2;i*i<=x;i++)
    {
      if(x%i==0)
      {
        temp.pb(i);      
        while(x%i==0) x/=i;
      }     
    }
    
   if(x>1) temp.pb(x);
    
   return temp;
}

void solve()
{
  int n,v;
    cin >> v >> n;
    
  vi s = fact(v);
    
  int ans = 1;
    
  for(auto x : s)   
  {
    int tot = 0;  
    int mx = x;
    
    if(mx > n) continue;  
      
    while(mx <= (n/x)) mx*=x;
      
    while(mx > 1)
    {   
      ans=(ans*pw(mx,n/mx - tot))%M;
      tot+=(n/mx-tot);  
      mx/=x;  
    }
         
  }
    
  cout << ans;  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}