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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

string s;
int n;

bool check(int k)
{
    int lim = k;
    
    for(int i=0;i<=n;i++)
    {
        if(i+1 > lim) return 0; 
        
        if(s[i] == 'R')
        {
            lim = i + k + 1;
        }
    }
    
    return 1;
}

void solve()
{
   
   cin >> s;
    
   n = s.length();
   
   int l = 1;
   int r = (n+1);
   int res = r;
    
   while(l<=r)
   {
       int mid = (l+r)/2;
       
       if(check(mid))
       {
           res = min(res,mid);
           r = mid - 1;
       }
       else l = mid + 1;
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