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

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


void solve()
{
   int m,n;
   cin >> m >> n;
    
   int a[m][n];
   f(i,m) f(j,n) cin >> a[i][j];
    
   int l = 1;
   int r = 1e9;
   int res=  l;
    
   while(l <= r)
   {
       int mid = (l + r)/2;
       
       int flag = true;
       int flag2 = false;
       
       vector<int> mx(n,0);
       f(i,m) f(j,n) mx[j] = max(mx[j] , a[i][j]);
       
       
       f(i,n) if(mx[i] < mid)
       {
           flag = false;
       }
       
       //if there is a shop where atleast two values are >= mid , done
       f(i,m)
       {
           int cnt = 0;
           f(j,n) if(a[i][j] >= mid) cnt++;
               
           if(cnt > 1) flag2 = true;
       }
       
       if(flag && flag2)
       {
           res = mid;
           l = mid + 1;
       }
       else r = mid - 1;
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