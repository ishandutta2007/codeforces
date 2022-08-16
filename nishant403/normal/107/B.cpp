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

double go(int a,int b,int c)
{
    double res = 1.000000;
    
    for(int i=1;i<=c;i++) res*=((double)b-i+1)/(a-i+1);
    
    return res;
}

void solve()
{
  int n,m,h;
  cin >> n >> m >> h;
    
  int s[m];
    
  f(i,m) cin >> s[i];
    
  h--;  
  s[h]--;
  n--;
    
  int sum = 0;
  f(i,m) sum+=s[i];
    
  if(sum < n)
  {
      cout << -1;
      return;
  }
    
  double res = 1.0000000 - go(sum,sum-s[h],n);
    
  cout << fixed << setprecision(6) << res;  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}