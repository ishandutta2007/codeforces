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
    
 int p[n];
    f(i,n) cin >> p[i];
    f(i,n) p[i]/=100;
    
 sort(p,p+n);   
    
 int x,a,y,b,k;
    cin >> a >> x;
    cin >> b >> y;
    
 cin >> k;
   
  int l = 1;
  int r = n;
  int ans = 1e8;
    
  while(l<=r)
  {
      int mid = (l+r)/2;
      
      int gg = __gcd(x,y);
      int lc = (x*y)/gg;
      int mix = mid/lc;
      
      int a1 = mid/x;
      int b1 = mid/y;
      
      a1-=mix;
      b1-=mix;
      
      int f = n-1;
      int taken = 0;
      
      f(i,mix) taken+=(a+b)*p[f--];
      
      int ff = f;
      int c1=0,c2=0;
      
      f(i,a1) c1+=a*p[f--];
      f(i,b1) c1+=b*p[f--];
      
      f(i,b1) c2+=b*p[ff--];
      f(i,a1) c2+=a*p[ff--];
      
      taken+=max(c1,c2);
      
      if(taken >= k)
      {
          ans=min(ans,mid);
          r = mid - 1;
      }
      else l = mid + 1;
  }
    
   if(ans < 1e8) cout << ans << '\n';  
   else cout <<"-1\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}