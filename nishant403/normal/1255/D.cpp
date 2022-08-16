#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

char mp[63];

void pre()
{
    f(i,10) mp[i+1] = i+'0';
    f(i,26) mp[i+11] = ('a'+i);
    f(i,26) mp[i+37] = ('A'+i);
}

void solve()
{
  int r,c,k,rice = 0;
    cin >> r >> c >> k;
    
 char grid[r][c];
    
 f(i,r) f(j,c)
 {
     cin >> grid[i][j];
     rice+=(grid[i][j]=='R');
 }
    
 int give = rice/k; 
 int extra = rice%k;
 int cur = 1;   
 int cnt = 0;   
    
 int ans[r][c];   
    
 f(i,r) f(j,c)
 {
   if(cur > k) cur = k;  
     
   if(i%2==0)  ans[i][j] = cur;
   else ans[i][c-j-1] = cur;  
     
   if(i%2 == 0 && grid[i][j]=='R') cnt++;
   else if(i%2 == 1 && grid[i][c-j-1]=='R') cnt++;  
     
   if(cnt == give+1 && extra > 0)
   {
         extra--; 
         cnt = 0;
         cur++;
   }
   else if(cnt == give && extra == 0)
   {
        cnt = 0; 
        cur++; 
   }
 }
     
     
 f(i,r)
 {
     f(j,c) cout << mp[ans[i][j]]; cout<<'\n';
 }
  
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