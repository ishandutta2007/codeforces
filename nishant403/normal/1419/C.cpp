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
   int n,x;
    cin >> n >> x;
    
   int a[n];
    f(i,n) cin >> a[i];
   
   int res = 2; 
  
   int ff = 1;
    
   f(i,n) if(x != a[i]) ff = 0;

   if(ff)
   {
       cout << 0 << '\n';
       return;
   }
   
   int there = 0;
    f(i,n) if(x == a[i]) there = 1;
        
   int sum = 0;
    f(i,n) sum+=a[i];
    
   if(sum == (n*x) || there) cout << 1 << '\n';
   else cout << 2 << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}