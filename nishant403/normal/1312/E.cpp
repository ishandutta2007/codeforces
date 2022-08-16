#include <bits/stdc++.h>
using namespace std;
  
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 504;
int dp[N][N];
int a[N];

int go(int l,int r)
{
    int & res = dp[l][r];
    
    if(res != -1) return res;
    
    if(l == r) return res = a[l];
    
    res = 0;
    
    for(int k=l;k<r;k++)
    {
        if(go(l,k) > 0 && go(l,k) == go(k+1,r) )
            return res = go(l,k) + 1; 
    }
    
    return res;
}

void solve()
{
   int n;
   cin >> n;
    
   f(i,n) cin >> a[i];
    
   memset(dp,-1,sizeof(dp));
    
   vector<int> len(n+1,n+20);
    
   len[0] = 0;
    
   for(int i=0;i<n;i++)
       for(int j=0;j<=i;j++)
            if(go(j,i) > 0) len[i+1] = min(len[i+1],len[j] + 1);
       
       
   cout << len[n]; 
}

signed main()
{
    fast;
    solve();
}