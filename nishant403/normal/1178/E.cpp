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
string s;
cin >> s;
    
 int n = s.length();
 int req = n/2;
  
 int l = 0,r = n-1;
      
 vector<char> ans;    
    
  char extra ;
  bool flag = 0;
    
 while(l<r)
 {
     if(req<=0) break;
     
     if(req == 1)
     {
      extra = s[l];
      flag = 1;
      req--;   
      break;
     }
     
     if(s[l] == s[r] ) { ans.pb(s[l]); l++; r--; }
     else if(l+1 < r && s[l+1] == s[r]) { ans.pb(s[r]); l+=2; r--; }
                                         
     else if(l < r-1 && s[r-1] == s[l]) {ans.pb(s[l]); l++; r-=2; }   
     else if(l+1 < r-1 && s[l+1] == s[r-1])
     {
         ans.pb(s[r-1]);
         l+=2;
         r-=2;
     }
                                         
     req-=2;
 }
    
    if(req > 0)
             {
               cout << "IMPOSSIBLE\n";
                 return;
             }
    
  
   for(int i=0;i<((int)ans.size());i++) cout << ans[i];
    
  if(flag) cout << extra; 
    
for(int i=((int)ans.size()-1);i>=0;i--) cout << ans[i];
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}