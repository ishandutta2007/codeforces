#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define precise(x) fixed << setprecision(x) 

const int N = 18;

double a[N][N];
double dp[(1LL<<N)];

double go(int n,int mask)
{
    int set_bit = __builtin_popcount(mask);
    
    double ret = 2.0000;
    ret /= set_bit*(set_bit - 1);
    return ret;
}

signed main()
{
    fast;
    
    int n;
    cin >> n;
        
    f(i,n) f(j,n) cin >> a[i][j];
    
    dp[(1LL<<n) - 1] = 1.0000000; 
    
    for(int i=(1<<n)-2;i>=1;i--)
    {
        f(j,n) if(i & (1<<j)) 
            f(k,n) if(!(i & (1<<k)))  
                dp[i] += dp[i|(1<<k)]*a[j][k]*go(n,i|(1<<k));
    }
    
    f(i,n) cout<< precise(6) << dp[1<<i] << ' ';
}