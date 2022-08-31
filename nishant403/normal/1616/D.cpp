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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int inf = 1e12;

void solve()
{
   int n;
   cin >> n;

   int a[n];
   f(i,n) cin >> a[i];

   int x;
   cin >> x;

   f(i,n) a[i] -= x;
   
   int res = n;

   for(int i=1;i<n;i++) {
       if(a[i-1] + a[i] < 0 || (i > 1 && a[i-2] + a[i-1] + a[i] < 0)) {
           a[i] = inf;
           res--;
       } 
   }

   cout << res << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}