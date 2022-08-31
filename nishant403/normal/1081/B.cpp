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
int n;
cin >> n;
    
vi a(n,0);
    
f(i,n) cin >> a[i];
    
map<int,vi> cc;    
    
f(i,n) cc[a[i]].pb(i);    
    
vi ans(n,0);
    
int cn = 0;    
int temp = 0;    
    
for(auto x : cc)
{
  for(auto z : x.S)
  {
      if(temp == 0)
      {
          temp = n-x.F;
          cn++;
      }
      
        ans[z] = cn;
        temp--;
      
  }
    
    if(temp!=0){cout << "Impossible\n"; return; }
}
    
   
cout << "Possible\n";
        
f(i,n) cout << ans[i] << " ";
    
    
    
    
}
 
signed main()
{
    fast;
    solve();
}