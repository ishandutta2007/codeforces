#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
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

int solve(vector<int> & a,vector<int> & b)
{
   int n = a.size();
   int m = b.size();
   
   if(n == 0 || m == 0) return 0; 
    
   set<int> st;
   vi fix(m,0);
    
   f(i,n) st.insert(a[i]);
   f(j,m) if(st.find(b[j]) != st.end()) fix[j] = 1;
   f(j,m-1) fix[j+1]+=fix[j]; 
    
   int ans = 0; 
    
   f(i,m)
   {
       int l = 1;
       int r = n;
       int res = 0;
       
       while(l <= r)
       {
           int mid = (l + r)/2;
           
           auto id = upper_bound(a.begin(),a.end(),b[i] + mid - 1) - a.begin();
           
           if(id >= mid)
           {
               res = mid;
               l = mid + 1;
           }
           else r = mid - 1;
       }
       
       if(res == 0) continue;
       
       int temp  = 0;
       //count of special positions from b[j] to b[j] + res
       temp += upper_bound(b.begin(),b.end(),b[i] + res - 1) - upper_bound(b.begin(),b.end(),b[i]-1);
       
       
       //count of fixed positions after b[j] + res + 1
       temp += fix[m-1];
       
       int idd = upper_bound(all(b),b[i] + res - 1) - b.begin() - 1;
       if(idd >= 0) temp -= fix[idd];
       
       ans = max(ans ,temp );
   }
    
   return ans;
}

void solve()
{
   int n,m;
    cin >> n >> m;
   
   int a[n],b[m];
    f(i,n) cin >> a[i];
    f(j,m) cin >> b[j];
  
   vi a1,a2,b1,b2;
   f(i,n) if(a[i] > 0) a1.pb(a[i]);
          else a2.pb(-a[i]);
       
   f(i,m) if(b[i] > 0) b1.pb(b[i]);
          else b2.pb(-b[i]);
       
   reverse(all(a2));
   reverse(all(b2));
       
   cout << solve(a1,b1) + solve(a2,b2) << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
   
    while(t--)
        
    solve();
}