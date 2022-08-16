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
 string s;
    
 cin >> a >> b;
 cin >> s;
    
 vi z;
 int cn = 0;
    
 for(auto x : s)
 {
  if(x=='.') cn++;
  else { z.pb(cn); cn=0;}
 }
    
 if(cn>0) z.pb(cn);
    
 for(auto x : z) 
     if(x>=b && x<a)
 {
   cout << "NO\n"; return;   
 }
  
 vi gt;
 vi real;   
    
 for(auto x : z) if(x>=2*b) gt.pb(x);
 for(auto x : z) if(x>=a) real.pb(x);       
     
 if(gt.size() >= 2) { cout<<"NO\n"; return; }       
 
  if(gt.size() > 0)
  {
 if(gt[0] < a) { cout<<"NO\n"; return; }
   
 for(int i=0;i<=gt[0]-a;i++)
 {
    int f = i; 
    int s = (gt[0]-a)-f; 
       
    if(f>=b && f<a) continue;
    if(s>=b && s<a) continue;
    if(f>=2*b) continue;
    if(s>=2*b) continue;
     
    int cc = 0;
     if(f>=a) cc++;
     if(s>=a) cc++;
     
     int v=cc-1;
     v+=((int)real.size());
     
     if(v%2==0) { cout<<"YES\n"; return; } 
 }
      
      cout<<"NO\n"; return;
      
}

if(real.size()%2 == 0) cout << "NO\n";
else cout <<"YES\n";    

}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}