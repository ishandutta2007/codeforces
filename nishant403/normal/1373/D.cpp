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

//n is even and first element is taken
int solve2(vector<int> & a)
{
    int n = a.size();
    
    int sum = 0;
    
    f(i,n/2) sum+=a[i+i];
    
    vi dif(n/2);
    
    f(i,n/2) dif[i] = (a[i+i+1] - a[i+i]);
    
    int cur = 0;
    int best = 0;
    
    f(i,n/2)
    {
        cur = max(dif[i],cur+dif[i]);
        best = max(best,cur);
    }
 
    return best + sum;
}

void solve()
{
   int n;
   cin >> n;
    
   vi a(n);
   f(i,n) cin >> a[i];
   
   vi b1 = a,b2 = a;
    
   if(n % 2 == 0)
   {
       b1 = a;
       b2.pop_back();
       reverse(b2.begin(),b2.end());
       b2.pop_back();
       cout << max(solve2(b1),solve2(b2) + a[0]) << '\n';
   }
   else
   {
       b1.pop_back();
       reverse(b2.begin(),b2.end());
       b2.pop_back();
       cout << max(solve2(b1) + a.back(),solve2(b2) + a[0]) << '\n';
   }
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}