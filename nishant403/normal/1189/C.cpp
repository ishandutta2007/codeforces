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
 f(i,n) cin >> a[i];
    
 int pre[n+1];
    
 pre[0] = 0;
    
 f(i,n) pre[i+1] = pre[i] + a[i];
    
 int q,l,r;
    
 cin >> q;
    
 while(q--)
 {
  cin >> l >> r;
     
  cout << (pre[r] - pre[l-1])/10 << "\n";   
     
 }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}