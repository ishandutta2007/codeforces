#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
  int n;
  cin >> n;
    
  string s;
  cin >> s;
    
  int up = 0;
  int down = 0;
    
  f(i,n) if(s[i] == '(') up++; else down++;
      
  if(up != down)
  {
      cout << -1;
      return;
  }
  
  int res = 0;
  int flag = 0;
  int sum = 0;  
    
  f(i,n)
  {
      if(s[i] == '(') sum++;
      else sum--;
      
      if(sum < 0) flag = 1;
      
      res+=flag;
      
      if(flag == 1 && sum == 0) flag = 0;
  }
    
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