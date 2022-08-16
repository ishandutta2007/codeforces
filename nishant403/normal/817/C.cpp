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

int dd(int i)
{
  int sum=0;
    while(i)
    {
     sum+=i%10;   
i/=10;    }
    return sum;
}

void solve()
{
  int n,s;
  cin >> n >> s;
    
  int ans = min(n,s);
    
  for(int i=s+1;i<=min(n,s+162);i++)
  {
    if(i-dd(i) < s) ans++;     
  }
      
  cout << n-ans;    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}