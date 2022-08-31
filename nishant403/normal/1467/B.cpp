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

const int N = 3e5 + 10;
int a[N];
int n;

bool check(int x)
{
    if(x <= 0 || x >= n-1) return 0;
    if(a[x-1] < a[x] && a[x] > a[x+1]) return 1;
    if(a[x-1] > a[x] && a[x] < a[x+1]) return 1;
    return 0;
}

int res = 0;
int sum = 0;

void go(int i,int val)
{
   int temp = a[i];
    
   int ans = sum;
    
   ans -=check(i-1) + check(i) + check(i+1);
   a[i] = val;
   ans +=check(i-1) + check(i) + check(i+1);

   res = min(res,ans);
   a[i] = temp; 
}

void solve()
{
   cin >> n;
    
   f(i,n) cin >> a[i];
    
   sum = 0;
   f(i,n) sum+=check(i);
   res = sum;
    
   f(i,n)
   {
       if(i > 0) go(i,a[i-1]);
       if(i < n-1) go(i,a[i+1]);
       go(i,-1e10);
       go(i,1e10);
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