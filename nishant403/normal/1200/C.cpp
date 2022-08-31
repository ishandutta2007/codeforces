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
 
void solve()
{
  int n,m,q,s[2],e[2];
  cin >> n >> m >> q;
    
  int gc=__gcd(n,m);
  int gapn = n/gc;  
  int gapm = m/gc;  
    
  while(q--)
  {
      int a0,b0,a1,b1;
      
      cin >> s[0] >> e[0] >> s[1] >> e[1];
      
      if(s[0] == 1)
      {
      b0 = ((e[0]+gapn-1)/gapn)*gapn;
      a0 = b0 - gapn; 
      }
      else
      {
       b0 = ((e[0]+gapm-1)/gapm)*gapm;
       a0 = b0 - gapm;
      }
      
      if(s[1] == 1)
      {
          b1 = ((e[1] + gapn -1)/gapn)*gapn;
          a1 = b1 - gapn;
      }
      else
      {
          b1 = ((e[1]+gapm-1)/gapm)*gapm;
          a1 = b1-gapm;
      }
      
      if(s[0] == 1 && s[1] == 2)
      {
        a0=(a0/gapn)*gapm;
        b0=(b0/gapn)*gapm;
      }
      else if(s[1] == 1 && s[0] == 2)
      {
        a1=(a1/gapn)*gapm;
        b1=(b1/gapn)*gapm;
      }
      
      if(a0 == a1 && b0==b1)  cout << "YES\n";
      else cout << "NO\n";
      
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