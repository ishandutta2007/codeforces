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

const int MOD = 998244353;

int mod_pow(int a,int b,int M = MOD)
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

int solve()
{
  int n,m;
    cin >> n >> m;
    
  int a[n];
    f(i,n) cin >> a[i];
    
  int b[m];
    f(i,m) cin >> b[i];
    
  vector<int> pse(n,-1);
    
  stack<int> st;
    
  for(int i=n-1;i>=0;i--)
  {
     while(!st.empty() && a[st.top()] > a[i])
     {
         pse[st.top()] = i;
         st.pop();
     }
      
     st.push(i);
  }
    
  int id = n-1; 
  
    
  int res = 1;  
    
  for(int i=m-1;i>=0;i--)
  {
      //first get to the point where we encouter b[i]. if there is any element less in the way quit.
      
      while(id >= 0 && a[id] > b[i]) id--;
      
      if(id == -1) return 0;
      
      if(a[id] < b[i]) return 0;
      
      int nex = pse[id];
     
      if(i == 0)
      {
          if(nex != -1) return 0;
          return res;
      }
      
      res=(res*(id-nex))%MOD;
      
      id = nex;
  }
          
    
   return res; 
}

signed main()
{
    fast;
    cout << solve();
}