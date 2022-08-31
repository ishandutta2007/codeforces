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

int dp[2001][2001];

string store[10] = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

bitset<7> a[2001];
bitset<7> go[10];

int n,k;

//we are at ith index and k remains.

int check(int i,int k)
{
    if(k < 0) return 0;
    
    if(i == n)
    {
        if(k == 0) return 1;
        else return 0;
    }
    
    if(dp[i][k] != -1) return dp[i][k];
   
    int res = 0;
    
    f(j,10)
    {
        if((a[i] | go[j]) != go[j]) continue;
        
        int taken = (a[i] ^ go[j]).count();
        
        res|=check(i+1,k-taken);
    }
    
    return dp[i][k] = res;
}

void solve()
{
   memset(dp,-1,sizeof(dp));
    
    
   f(i,10) f(j,7) if(store[i][6-j] == '1') go[i][j] = 1;
                  else go[i][j] = 0;
    
    cin >> n >> k;
    f(i,n) cin >> a[i];
    
  f(i,n) f(j,k+1) check(i,j);
   
  if(dp[0][k] == 0)
  {
      cout << -1;
      return;
  }
    
     
  f(i,n)
  {
      for(int j=9;j>=0;j--)
      {
        if((a[i] | go[j]) != go[j]) continue;
        
        int taken = (a[i] ^ go[j]).count();
        
        if(check(i+1,k-taken) == 1)
        {
            cout << j;
            k-=taken;
            break;
        }
      }
      
      
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