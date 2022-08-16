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
    
 pii data[n];
    f(i,n) cin >> data[i].F >> data[i].S ;
 
 int ma = 0;
    f(i,n) ma =max(ma,data[i].F);
    
 if(ma >= x){ cout << 1 << "\n"; return; }
    
 int dec = 0;
    
 f(i,n) dec=max(dec,data[i].F-data[i].S);
     
  if(dec==0) { cout << -1 << "\n"; return; }
 
 int reach = ma;   
 int cur = x;   
    
 cout << (x-ma+dec-1)/dec+1 << "\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}