//I think someone has hacked long long to int
#include <bits/stdc++.h>
using namespace std;
 
//#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
 
const int M = 700;
const int N = 5e5+10;
 
int dp[M+4][M+4];
int a[N];
 
void solve()
{
  int n,t,x,y;
  cin >> n;
    
  while(n--)
  {
     cin >> t >> x >> y;   
      
     if(t==2)
     {
       int ans = 0;
       
       if(x >= M)
       {
         for(int i=y;i<=N-1;i+=x) ans+=a[i];  
       }
       else ans=dp[x][y];   
        
       cout << ans << "\n";  
     }
     else
     {
      a[x]+=y;   
      for(int i=1;i<=M;i++) dp[i][x%i]+=y;   
     }
      
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