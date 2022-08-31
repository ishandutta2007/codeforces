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

const int N = 3e3 + 100;
const int INF = 1e18;

int dp[N][N];
int a[N];
int b[N];
int c[N];
int n;


//Key Idea :

//"a" sorted in strictly increasing => "b" sorted in non-decreasing
//the resulting sequence has no new elements 

//DP[i][j] : 
//make first i elements non decreasing order
//these elements take values from first j elements (these are sorted)

int solve(int i,int j)
{
    if(i == -1) return 0;
    if(j < 0) return INF;
    
    int & res = dp[i][j];
    if(res != -1) return res;
    
    res = INF;
    
    res = min(res , solve(i,j-1));
    res = min(res , solve(i-1,j) + abs(b[i] - c[j]));
    
    return res;
}

void solve()
{
    cin >> n;
    f(i,n) cin >> a[i];
    f(i,n) b[i] = a[i] - i;
    f(i,n) c[i] = b[i];
    sort(c,c+n);
    
    f(i,n) f(j,n) dp[i][j] = -1;
    cout << solve(n-1,n-1) << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}