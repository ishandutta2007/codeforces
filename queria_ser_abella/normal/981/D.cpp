#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100100
#define debug 


ll cur = 0;
ll v[55];
int k,n;

int dp[60][60];

int get(int pos,int val){
    if(pos == n)
        return (val == k);
    if(dp[pos][val]+1)
        return dp[pos][val];
    ll s = 0;
    int ok = 0;
    for(int i=pos;i<n;i++){
        s += v[i];
        if((s&cur) != cur)
            continue;
        if(get(i+1,val+1))
            ok = 1;
    }
    return dp[pos][val] = ok;
}

main(){
    
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lld",v+i);
        
        
    for(int i=55;i>=0;i--){
        cur += (1ll << i);
        debug("oi i %d cur %lld\n",i,cur);
        memset(dp,-1,sizeof(dp));
        if(get(0,0) == 0)
            cur -= (1ll << i);
    }
    
    printf("%lld\n",cur);
    
}