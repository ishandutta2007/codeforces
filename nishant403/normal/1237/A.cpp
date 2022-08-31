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
    
    int a[n],b[n];
    f(i,n) cin >> a[i];
    f(i,n) b[i] = a[i];
    
    f(i,n)
    {
      if( ((a[i]%2)+2)%2 == 1)
        a[i]--;
    }
    
    int need = 0;
    
    f(i,n) need+=a[i]/2;
    
    f(i,n)
    {
      if(need < 0 && (((b[i]%2)+2)%2 == 1))
      {
        a[i]+=2;
        need++;  
      }
    }
        
    f(i,n) cout << a[i]/2 << "\n";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}