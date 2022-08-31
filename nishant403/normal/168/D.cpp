#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

double dp[2][205][205];
int n,l,k,a[205],b[205];

void solve()
{
}

int main()
{
fast;
       
cin >> n >> l >> k;
        
f(i,n) cin >> a[i];
f(i,n) cin >> b[i];
    
f(i,n+1) f(j,n+1) dp[0][i][j] = 0.000000;
    
dp[0][0][min(n,k)] = 1.000000;    
    
f(kk,n)
{
    double p = a[kk]/(double)100.000;
    
    f(i,n+1) f(j,n+1) dp[(kk+1)%2][i][j]  = 0.000000;
    
    for(int i=0;i<=kk;i++)
        for(int j=0;j<=n;j++)
    {
        dp[(kk+1)%2][i+1][min(n,b[kk]+1+j)] += dp[kk%2][i][j]*p;
        dp[(kk+1)%2][i][j] += dp[kk%2][i][j]*(1-p);
    } 
}
    
 double ans = 0;    
    
 for(int i=l;i<=n;i++)
     for(int j=i;j<=n;j++) ans+=dp[n%2][i][j];
    
 cout << fixed << setprecision(10) << ans;
}