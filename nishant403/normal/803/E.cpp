#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e3 + 10;
const int off = 1001;

int dp[N][N+N+10];
int par[N][N+N+10];

void solve()
{
   int n,k;
    cin >> n >> k;
    
   string s;
    cin >> s;
    
   dp[0][off] = 1; 
   par[0][off] = -1; 
    
   int id = 1; 
    
   for(auto x : s)
   {
       for(int i=off-k;i<=off+k;i++)
       {
           if(x == 'D' && (i != off + k && i != off - k))
           {
               dp[id][i] = dp[id-1][i];
               par[id][i] = i;
           }
           else if(x == 'L' && i + 1 < off + k)
           {
               dp[id][i] = dp[id-1][i+1];
               par[id][i] = i+1;
           }
           else if(x == 'W' && i - 1 > off - k)
           {
               dp[id][i] = dp[id-1][i-1];
               par[id][i] = i-1;
           }
           else if(x == '?')
           {
               if(i + 1 < off + k) dp[id][i] |= dp[id-1][i+1];
               if(dp[id][i])
               {
                   par[id][i] = i+1;
                   continue;
               }
               if(i - 1 > off - k) dp[id][i] |= dp[id-1][i-1];
               if(dp[id][i])
               {
                   par[id][i] = i-1;
                   continue;
               }
               if((i != off + k && i != off - k)) dp[id][i] |= dp[id-1][i];
               if(dp[id][i])
               {
                   par[id][i] = i;
                   continue;
               }
           }
       }
       
       id++;
   }


   if(dp[n][k+off] == 0 && dp[n][off-k] == 0) cout << "NO\n";
   else
   { 
        string res;   
       
        int i = n;
        int j = k + off;
       
        if(dp[n][k+off] == 0) j = off - k;
       
       while(i > 0)
       {
           if(par[i][j] == j-1) res+='W';
           else if(par[i][j] == j+1) res+='L';
           else res+='D';
           j = par[i][j];
           i--;
       }
       
       reverse(res.begin(),res.end());
       cout << res;
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