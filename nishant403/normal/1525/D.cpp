#include <bits/stdc++.h>
using namespace std;
  
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

const int N = 5e3 + 100;

int n;
int a[N];
int dp[N];
int go[N][N];

void pre()
{
    
    for(int i=0;i<n;i++)
    {
        vector<int> ids;
        int temp = 0;

        for(int j=i;j<n;j++)
        {
            if(a[j] == 0)
            {
                ids.pb(j);
            }
            else if(ids.empty()) temp = 1e9;
            else
            {
                temp += j - ids.back();
                ids.pop_back();
            }
            
            go[i][j] = min(go[i][j],temp);
        }
        
        ids.clear();
        temp = 0;
        
        for(int j=i;j>=0;j--)
        {
            if(a[j] == 0) ids.pb(j);
            else if(ids.empty()) temp = 1e9;
            else
            {
                temp += ids.back() - j;
                ids.pop_back();
            }
            
            go[j][i] = min(go[j][i] , temp);
        }
    }    
}

void solve()
{
   cin >> n;
   f(i,n) cin >> a[i];
   
   f(i,n) dp[i] = 1e9;
   f(i,n) f(j,n) go[i][j] = 1e9; 
    
   pre(); 
    
   for(int i=0;i<n;i++)
   {
       dp[i] = go[0][i];
       
       for(int j=0;j<i;j++) 
           dp[i] = min(dp[i] , dp[j] + go[j+1][i]);
   }
    
   cout << dp[n-1] << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
  //  cin >> t;
    
    while(t--)
        
    solve();
}