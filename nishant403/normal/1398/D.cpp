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
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 204;

int dp[N][N][N];
int a[N];
int b[N];
int c[N];

int solve(int i,int j,int k)
{
    if(i < 0 || j < 0 || k < 0) return 0;
    
    int & res = dp[i][j][k];
    
    if(res != -1) return res;
    
    res = 0;
    
    if(i >= 0 && j >= 0) res = max(res,a[i]*b[j] + solve(i-1,j-1,k));
    if(i >= 0 && k >= 0) res = max(res,a[i]*c[k] + solve(i-1,j,k-1));
    if(j >= 0 && k >= 0) res = max(res,c[k]*b[j] + solve(i,j-1,k-1));
    
        
    return res;
}

void solve()
{
    int x,y,z;
    cin >> x >> y >> z;
    
    f(i,x+1) f(j,y+1) f(k,z+1) dp[i-1][j-1][k-1] = -1;
      
    f(i,x) cin >> a[i];
    sort(a+1,a+x+1);
    
    f(i,y) cin >> b[i];
    sort(b+1,b+y+1);
    
    f(i,z) cin >> c[i];
    sort(c+1,c+z+1);
    
    cout << solve(x,y,z);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}