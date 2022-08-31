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

const int N =2e5+10;

int flow[N][2][2];

void solve()
{
  int n;
  cin >> n;
    
  f(i,n+2) 
      f(k,2) 
        flow[i][k][0] = flow[i][k][1] = 0;  
    
  int data[n+1][2];
   
  string s[2];
    cin >> s[0];
    cin >> s[1];
    
  f(j,2) 
  f(i,n) data[i+1][j] = s[j][i]-'0';
    
  flow[1][0][0] = 1;  
    
  for(int i=1;i<=n;i++)  
  {    
      {
    if(data[i][0] < 3)
        flow[i+1][0][0] = flow[i][0][0];
      
    else
    {
        flow[i][1][1] = flow[i][0][0];   
    }
      }
      
      {
    if(data[i][1] < 3)
        flow[i+1][1][0] = flow[i][1][0];
      
    else  flow[i][0][1] = flow[i][1][0];
      }
      
    if(data[i][0] > 2)    
      flow[i+1][0][0] = flow[i][0][1];  
        
    if(data[i][1] > 2)
      flow[i+1][1][0] = flow[i][1][1];  
  }
    
    
    
  if(flow[n+1][1][0] == 1) cout << "YES\n";
  else cout << "NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}