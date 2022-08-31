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

const int MOD = 998244353;

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


const int N = 5e5 + 10;

int fact[N];
int ifact[N];

void init()
{
    fact[0] = 1;
    
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*i)%MOD;
    
    ifact[N-1] = mod_pow(fact[N-1],MOD-2);
    
    for(int i=N-2;i>=0;i--) 
        ifact[i] = (ifact[i+1]*(i+1))%MOD;
}

int ncr(int n,int r)
{
 if(r>n) return 0;
    
 int res = fact[n];
    
 res = (res*ifact[r])%MOD;
 res = (res*ifact[n-r])%MOD;
    
  return res;
}

void solve()
{
   int n,k;
    cin >> n >> k;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   int res = 0;
    
   vector<int> pos(n);
    f(i,n) pos[a[i]] = i;
    
   f(i,n-1)
   {
       if(a[i] != n-1 && a[i+1] != n-1)
       {
           res +=(pos[a[i] + 1] < pos[a[i+1] + 1]);
       }
       else if(a[i] == n-1)
       {
           res++;
       }
   }
    
   cout << ncr(res+k,n); 
}

signed main()
{
    init();
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}