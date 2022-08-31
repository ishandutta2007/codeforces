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

//exp[i] = 1 + (p[i]/100)*exp[i+1] + (1 - p[i]/100)*exp[1],i != n
//exp[n] = 1 + (1 - p[i]/100)*exp[1], i = n
//solve this equations in reverse order, exp[i] can be expressed as,
//exp[i] = a + b*exp[1]
//this way we can solve the equations

const int M = 998244353;

int pw(int a,int b)
{
    int res = 1;
    
    while(b)
    { 
       if(b&1) res=(res*a)%M;
       a=(a*a)%M;
       b>>=1;
    }
    
    return res;    
}

void solve()
{
  int n;
  cin >> n;
    
  int p[n+1];   
  f(i,n) cin >> p[i];
    
  int den = pw(100,M-2);  
    
  pii xx[n+2];  
  f(i,n+2) xx[i].F = xx[i].S = 0;  
    
  f(i,n) p[i] =(p[i]*den)%M;  
         
 //as we know, exp[i] = 1 + exp[i+1]*p[i] + (1-p[i])*exp[1]
 //exp[i] = 1 + (a+b*exp[1])*p[i] + (1-p[i])*exp[1]
 //exp[i].F = (1 + a*p[i])  
 //exp[i].S = b*p[i] + (1-p[i])
    
  for(int i=n;i>=1;i--)
  {
      xx[i].F = (1 + (xx[i+1].F*p[i])%M)%M;
      xx[i].S = (xx[i+1].S*p[i])%M;
      xx[i].S += ((1-p[i])%M + M)%M;
      xx[i].S %=M;
  }
    
  int a1 = xx[1].F;
  int a2 = ((1-xx[1].S)%M+M)%M;
    
  a2 = pw(a2,M-2);
    
  a1 = (a1*a2)%M;
    
  cout << a1;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}