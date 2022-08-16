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

int m,d,n;
string a,b;
int pw[2006];
int dp[2005][2003][2];

int go(int dg,string & s,int md,int flag)
{
    if(dg == n) return (md == 0);
    
    int & res = dp[dg][md][flag];
    
    if(res != -1) return res;
    res = 0;
    
    int l = 0;
    int r = 9;
   
    if(flag == 1) r = s[dg]-'0';
    
    for(int i=l;i<=r;i++)
    {
        if(dg%2 == 0 && i==d) continue;
     
        if(dg%2 == 1 && (i!=d)) continue;
        
        int fn = (i==r && flag == 1);
        int add = (pw[n-dg-1]*i)%m;
        
        res = (res  + go(dg+1,s,(add+md)%m,fn))%MOD;
    }
    
    return res;
}

void solve()
{
   cin >> m >> d;
   cin >> a >> b;
    
   pw[0] = 1;
    
   for(int i=1;i<=2000;i++) pw[i] = (pw[i-1]*10)%m;
    
   n = a.length();
    
   memset(dp,-1,sizeof(dp)); 
    
   int res = go(0,b,0,1);
    
   if(!(n == 1 && a[0] == '0'))
   {
       for(int i = n-1;i>=0;i--) if(a[i] > '0') 
       {
          a[i]--;
          break;
       }
       else a[i] = '9';
       
       memset(dp,-1,sizeof(dp));
       
       res = (res - go(0,a,0,1) + MOD)%MOD;
   }
    
   cout << res; 
}

signed main()
{
    fast;
    solve();
}