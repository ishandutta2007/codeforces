#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

bool cmp(pii & a,pii & b)
{
    if(a.F > b.F) return 1;
    if(a.F < b.F) return 0; 
    if(a.S < b.S) return 1;
    
    return 0;
}

void solve()
{
  int n;
  cin >> n;
    
  pii a[n];
    
  int b[n];  
    
  f(i,n) cin >> a[i].F;
  f(i,n) b[i] = a[i].F;  
  f(i,n) a[i].S = i;
    
  sort(a,a+n,cmp);
  
  int m;
  cin >> m;  
    
  pair<pii,int> q[m];  
    
  f(i,m) cin >> q[i].F.F >> q[i].F.S;
  f(i,m) q[i].S = i;
    
  sort(q,q+m);
    
  ordered_set os;
    
  pii ans[m];
    
       
  f(i,m)
  {
    while(os.size() < q[i].F.F) os.insert(a[os.size()].S);   
      
    ans[i].S = *os.find_by_order(q[i].F.S-1);
    ans[i].F = q[i].S;  
  }
    
   
  sort(ans,ans+m);
  
  f(i,m) cout << b[ans[i].S] << '\n';
    
}

signed main()
{
    fast;
    solve();
}