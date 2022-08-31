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

const int N = 504;
int dp[N][N];
string s;

vector<int> pos[26];

int solve(int l,int r)
{
    if(l > r) return 0;
    else if(l == r) return 1;
    
    int & res = dp[l][r];
    
    if(res != -1) return res;
    
    res = r - l + 1;
    
    //how to delete the first character ?
    
    int id = s[l] - 'a';
    int ps = lower_bound(all(pos[id]),l) - pos[id].begin();
    
    res = min(res,1 + solve(l+1,r));
    
    while(1)
    {
        if(pos[id][ps+1] <= r) ps++;
        else break;
        
        res = min(res,solve(l+1,pos[id][ps] - 1) + solve(pos[id][ps],r));
    }
    
    return res;
}
    
void solve()
{
   int n;
   cin >> n;
   
   cin >> s;
   
   memset(dp,-1,sizeof(dp));
    
   f(i,n) pos[s[i] - 'a'].pb(i);
   f(i,26) pos[i].pb(n); 
    
   cout << solve(0,n-1);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}