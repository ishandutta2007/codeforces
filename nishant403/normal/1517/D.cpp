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
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
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

const int N = 504 + 10;
const int inf = 1e9;
int dp[N][N][11];
int a[N][N];
int b[N][N];

vector<pair<int,pii> > g[N][N];

void solve()
{
   int n,m,k;
    cin >> n >> m >> k;
   
   if(k & 1)
   {
       f(i,n)
       {
           f(j,m) cout << -1 << ' ';
           cout << '\n';
       }
       
       return;
   }
    
   k/=2;
    
   f(i,n) f(j,m-1) cin >> a[i][j];
   f(i,n-1) f(j,m) cin >> b[i][j];
    
   f(i,n) f(j,m-1)
   {
       g[i][j].pb({a[i][j],{i,j+1}});
       g[i][j+1].pb({a[i][j],{i,j}});
   }
    
   f(i,n-1) f(j,m)
   {
       g[i][j].pb({b[i][j],{i+1,j}});
       g[i+1][j].pb({b[i][j],{i,j}});
   }
   
   f(i,n) f(j,m) f(z,k+1) dp[i][j][z-1] = inf;
    
   f(i,n) f(j,m) dp[i][j][0] = 0;
    
  for(int z=1;z<=k;z++)
    f(i,n) f(j,m) 
       for(auto x : g[i][j])
           dp[i][j][z] = min(dp[i][j][z] , x.F + dp[x.S.F][x.S.S][z-1]);
       
   f(i,n)
   {
       f(j,m) cout << 2*dp[i][j][k] << ' ';
       cout << '\n';
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