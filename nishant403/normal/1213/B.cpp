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
    
   int a[n];
    f(i,n) cin>> a[i];
    
   int nse[n];
    
    stack<int> ss;
    
    f(i,n)
    {
     while(!ss.empty() && a[ss.top()] > a[i] )
     {
       auto x = ss.top(); ss.pop();
         nse[x] = i;
     }
        
     ss.push(i);   
    }
    
    int ans = n-ss.size();
    
        cout << ans << "\n";
        
        
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}