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
  int a,b;
  cin >> a>> b;
    
  if(a>b) swap(a,b);
  
  if(a==b)
  {
      cout<<"0\n";
      return;
  }
   
   int sum = 0; 
   int diff = b-a;
    
  for(int i=1;;i++)
  {
      sum+=i;
      
      if(sum>=diff && ((sum-diff)%2 == 0))
      {
        cout << i << endl; return;
      }
  }
   
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}