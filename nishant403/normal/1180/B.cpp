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

bool comp(const pii & a,const pii & b)
{
 return a.S < b.S;   
}

void solve()
{
  int n;
  cin >> n;
   
 vector<pii> a(n);   
 
    f(i,n) { cin >> a[i].F; a[i].S = i; }
    


f(i,n) if(a[i].F < 0) a[i].F = -a[i].F-1;
    
    
  sort(a.begin(),a.end()); 
    
if(n%2 == 0)
{
  f(i,n) if(a[i].F>= 0) a[i].F = -a[i].F-1;   
}
else
{
 f(i,n-1) if(a[i].F>=0) a[i].F = -a[i].F-1;   
}
    
  sort(a.begin(),a.end(),comp);  
    
    f(i,n) cout << a[i].F << " ";
}

signed main()
{
    fast;
    solve();
}