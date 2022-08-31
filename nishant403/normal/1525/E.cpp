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

const int N = 22;
const int M = 5e4 + 10;

int n,m;
int a[N][M];
int ncr[N][N];
int fct[N];

void solve()
{
   cin >> n >> m;
   f(i,n) f(j,m) cin >> a[i][j];
    
   int res = 0;
    
   f(j,m) 
   {
       //find number of permutations we cannot access this point
       vector<int> tm;
       vector<int> fre(n+5,0);
       
       f(i,n) fre[n + 1 - a[i][j]]++;
       
       int places = 0;
       
       int rr = 1;
       
       for(int i=n;i>=0;i--)
       {
           if(fre[i] > places) 
           {
               rr = 0;
               break;
           }
           else
           {
               rr = (rr*ncr[places][fre[i]]);
               places -= fre[i];
           }
           
           places++;
       }
       
       res += fct[n] - rr;
       res %= MOD;
       if(res < 0) res += MOD;
   }
    
   res = (res*mod_pow(fct[n],MOD-2))%MOD;
   cout << res;
}

signed main()
{
    for(int i=0;i<N;i++)
    {
        ncr[i][0] = 1;
        
        for(int j=1;j<=i;j++)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%MOD;
    }
    
    fct[0] = 1;
    for(int i=1;i<N;i++) fct[i] = (fct[i-1]*i)%MOD;
    
   for(int i=0;i<N;i++)
       for(int j=0;j<=i;j++) ncr[i][j] = (ncr[i][j]*fct[j])%MOD;
    
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}