#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pb push_back
#define maxn 5050
#define ll long long
#define debug 
using namespace std;

int h[maxn];
int dp[2][maxn][maxn];
int n;

inline int get(int ok,int pos,int k){
    int & ret = dp[ok][pos][k];
    if(ret+1)
        return ret;
    if(k == 0)
        return 0;
    if(pos >= n)
        return 1e9;
    ret = 1e9;
    if(ok){
        int nxt = -10000;
        if(pos != n-1) nxt = h[pos+1];
        ret = min(ret,dp[0][pos+2][k-1] + max(0,nxt-h[pos]+1));
        int dec = max(0,nxt-h[pos]+1);
        if(pos < n-2){
            dec = max(dec,nxt-h[pos+2]+1);
            ret = min(ret,dp[1][pos+2][k-1] + dec);
        }
    }
    
    ret = min(ret,dp[0][pos+1][k]);
    int r = max(0,h[pos]-h[pos+1]+1);
    ret = min(ret,dp[1][pos+1][k]+r);
    
    debug("dp[%d][%d][%d] = %d\n",ok,pos,k,ret);
    return ret;

}

main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",h+i);
    memset(dp,-1,sizeof(dp));
    for(int pos=n+1;pos>=0;pos--)
        for(int k=0;k<=(n+1)/2;k++){
            dp[0][pos][k] = get(0,pos,k);
            dp[1][pos][k] = get(1,pos,k);
        }
    for(int i=1;i<=(n+1)/2;i++)
        printf("%d ",dp[1][0][i]);
}