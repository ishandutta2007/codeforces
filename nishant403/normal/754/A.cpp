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
    
  int a[n],sum = 0;
  f(i,n) cin >> a[i];
    
  int flag = -1;
    
  f(i,n) if(a[i] != 0) flag = i;
      
  if(flag == -1)
  {
      cout <<"NO\n"; return;
  }
  
  cout <<"YES\n";  
    
  f(i,n) sum+=a[i];
    
  if(sum != 0) cout <<1 << "\n" << 1 <<" "<<n;
  else cout << 2 <<"\n" << 1 <<" " << flag <<"\n" << flag+1 <<" "<<n;
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}