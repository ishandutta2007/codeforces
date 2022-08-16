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

//01 type ignored
//00 is 0
//11 is 1
//x0 is x1 are separately counted.

void solve()
{
  int n;
  cin >> n;
    
  if(n == 1)
  { cout << 0; return; }


  int a[n];
  f(i,n) cin >> a[i];
    
  f(i,n) if(a[i] == 0) a[i] = -1;
         else a[i] = a[i]%2;
      
  int cnt[2] = {0};
    
  cnt[0] = n/2;
  cnt[1] = (n+1)/2;
    
  f(i,n) if(a[i] != -1) cnt[a[i]]--;
      
  vector<pair<pii,int> > space;
      
  int last = -1;
  int len = 0;
  int ans = 0;
  vi xo;
  vi xz;
  
  f(i,n-1) if(a[i]!=-1 && a[i+1]!=-1) ans+=a[i]^a[i+1];  
    
  f(i,n)
  {
      if(a[i] != -1)
      {
          if(len == 0)
          {
              last = a[i];
              continue;
          }
          
          if(last == -1)
          {
              if(a[i] == 0) xz.pb(len);
              else xo.pb(len);
          }
          else
          {
             if((a[i]^last) == 1) ans++;
             else space.pb({{-2,len},a[i]}); 
          }
                  
          len = 0;
          last = a[i];
      }
      else len++;
  }
  
  if(len > 0)
  {
      if(last == 0) xz.pb(len);
      else if(last == 1) xo.pb(len);
      else
      {
          cout << 1; return;
      }
  }
  
  for(auto x : xo) space.pb({{-1,x},1});  
  for(auto x : xz) space.pb({{-1,x},0});  
    
  sort(space.begin(),space.end());
    
  for(auto x : space)
  {
      if(x.F.S <= cnt[x.S]) cnt[x.S]-=x.F.S;
      else ans-=x.F.F;
  }
    
  cout << ans;  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}