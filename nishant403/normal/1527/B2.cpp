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

const int N = 1e3 + 10;
int dp[N][N][2][2];

//n means pair of zeros
//m means single zero
//palindrome can be performed if m = 0
//mid-cell is zero/one

int solve(int n,int m,int pal,int md)
{
    if(n == 0 && m == 0 && md == 0) return 0;
    
    int & res = dp[n][m][pal][md];
    
    if(res != -1) return res;
    
    res = 1e9;
    
    if(n > 0) res = min(res,1 - solve(n-1,m+1,1,md));
    if(m > 0) res = min(res,1 - solve(n,m-1,1,md));
    if(md > 0) res = min(res,1 - solve(n,m,1,0));
    
    if(m != 0 && pal == 1)
        res = min(res,-solve(n,m,0,md));
    
    return res;
}

void solve()
{
   int n;
   cin >> n;
    
   string s;
   cin >> s;
   
   int full = 0;
   int half = 0;
    
   f(i,n/2)
   {
       if(s[i] == '0' && s[n-i-1] == '0') full++;
       else if(s[i] != '1' ||  s[n-i-1] != '1') half++;
   }
    
   int num = -1;
    
   if(n % 2 == 0) num = solve(full,half,1,0);
   else num = solve(full,half,1,s[n/2] == '0');
    
   if(num == 0) cout <<"DRAW\n";
   else if(num > 0) cout <<"BOB\n";
   else cout <<"ALICE\n";    
}

signed main()
{
    memset(dp,-1,sizeof(dp));
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}