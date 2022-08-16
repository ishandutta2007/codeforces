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

const int N = 2e5+10;
int dp[N];

void solve()
{
   int n;
   cin >> n;
   
    
   pii a[n];
   f(i,n) cin >> a[i].F;
   f(i,n) a[i].S = i;
    
   sort(a,a+n);
  
   if(n <= 5)
   {
         cout << a[n-1].F-a[0].F << " 1\n";
        f(i,n) cout << 1 << " ";
         return;
   }
   
   int d[n];  
   int cut[n];
   
   d[0] = 0;
    
   f(i,n-1) d[i+1] = a[i+1].F - a[i].F;
     
   dp[3] = d[3],cut[3] = 1;
    
   for(int i=4;i<=n-3;i++) 
   {
      if(dp[i-1] < d[i] + dp[i-3]) cut[i] = 1; 
      dp[i] = max(dp[i-1],d[i] + dp[i-3]); 
   }
    
   int ans = dp[n-3];
    
   vector< vector<int> > group;
    vector<int> temp;
    
   for(int i=n-1;i>=0;i--)
   {
      temp.pb(i); 
       
      if(cut[i] == 1)
      {
         group.pb(temp); 
         temp.clear();
         temp.pb(i-1); 
         temp.pb(i-2); 
         i-=2; 
      }
   }
    
   if(!temp.empty()) group.pb(temp); 
    
   int hh[n];
    
   for(int i=0;i<group.size();i++)
   {
      for(int j=0;j<group[i].size();j++)
      {
         hh[a[group[i][j]].S] = i+1;   
      }
   }
    
   cout << a[n-1].F - a[0].F - ans << " "<<group.size() << '\n';
    
   f(i,n) cout << hh[i] <<" "; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}