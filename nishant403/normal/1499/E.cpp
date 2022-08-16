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

const int MOD = 998244353;

const int N = 1006;
int dp[N][N][2];

void solve()
{
   string s,t;
   cin >> s >> t;
    
   int n = s.length();
   int m = t.length();
   
   for(int i=0;i<=n;i++)
       for(int j=0;j<=m;j++)
           for(int k=0;k<=1;k++)
   {
       //dp[i][j][k] : consider first i characters of s and 
       //              consider first j characters of t
       //              k determines the last character 
       //take all the combination of suffixes 
       //find f values for that strings.
       
       if(i == 0 && j == 0) continue;
       else if(i > 0 && j == 0)
       {
           if(k == 0)
           {
               dp[i][j][k] = 1;
               if(i > 1 && s[i-1] != s[i-2]) dp[i][j][k] += dp[i-1][j][k];
           }
       }
       else if(i == 0 && j > 0)
       {
           if(k == 1)
           {
               dp[i][j][k] = 1;
               if(j > 1 && t[j-1] != t[j-2]) dp[i][j][k] += dp[i][j-1][k];
           }
       }
       else if(i > 0 && j > 0)
       {
           if(k == 0)
           {
               //case 1 : the only character from s is s[i].
               if(i > 1 && s[i-1] != t[j-1]) dp[i][j][0] += dp[0][j][1];
               
               //case 2 : recurse for dp[i-1]... 2nd last is from s
               if(i > 1 && s[i-1] != s[i-2]) dp[i][j][0] += dp[i-1][j][0];
               
               //case 3 : recurse for dp[i-1]... 2nd last is from t
               if(s[i-1] != t[j-1]) dp[i][j][0] += dp[i-1][j][1];
           }
           else
           {
               if(j > 1 && s[i-1] != t[j-1]) dp[i][j][1] += dp[i][0][0];
               
               if(j > 1 && t[j-1] != t[j-2]) dp[i][j][1] += dp[i][j-1][1];
               
               if(s[i-1] != t[j-1]) dp[i][j][1] += dp[i][j-1][0];
           }
       }
       
       dp[i][j][k]%=MOD;
   }
    
   int res = 0;
    
   for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
           for(int k=0;k<=1;k++)
               res = (res + dp[i][j][k])%MOD;
   
   cout << res;    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}