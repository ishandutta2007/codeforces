#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int M = 1e7 + 10;
int spf[M];

void pre()
{
    spf[0] = spf[1] = -1;
    
    for(int i=2;i<M;i++)
    {
        if(spf[i] == 0)
        {
            for(int j=i;j<M;j+=i) spf[j] = i; 
        }  
    }
}

const int N = 2e5 + 10;
int dp[N][21];

int last[M];

int make(int x)
{
    int res = 1;
    
    while(spf[x] != -1)
    {
        int pr = spf[x];
        int cn = 0;
        
        while(x % pr  == 0)
        {
            x/=pr;
            cn^=1;
        }
        
        if(cn) res*=pr;
    }
    
    return res;
}

void solve()
{
   int n,k;
   cin >> n >> k;
   
   int a[n+1];
   f(i,n) cin >> a[i+1];
   f(i,n) a[i+1] = make(a[i+1]);
    
   vector<int> elms; 
    
   for(int i=1;i<=n;i++)
       for(int j=0;j<=k;j++) dp[i][j] = N;
       
   for(int i=1;i<=n;i++)
   {   
       if(last[a[i]] != 0) elms.pb(last[a[i]]);
       
       sort(all(elms));
       
       reverse(all(elms));
       
       while((int)elms.size() > k+1) elms.pop_back();
       
       reverse(all(elms));
       
       int sz = elms.size();
       
       //we try to change j elements
       for(int j=0;j<=min(sz,k);j++)
       {
           int id = 0;
           if(j != sz) id = elms[sz - 1 - j];
              
           for(int v=j;v<=k;v++)
               dp[i][v] = min(dp[i][v] , dp[id][v-j] + 1);
       }
       
       last[a[i]] = i;
   }
   
   cout << dp[n][k] << '\n';
    
   f(i,n) last[a[i+1]] = 0; 
}

signed main()
{
    pre();
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}