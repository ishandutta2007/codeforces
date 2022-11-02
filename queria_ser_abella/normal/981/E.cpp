#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200200
#define debug 

int ans[maxn];

struct qr {
    int l,r,val;
    bool operator<(qr comp)const{
        return l < comp.l;
    }
}

q[maxn];

int dp[maxn];

main(){
    
    int n,nq;
    scanf("%d%d",&n,&nq);

    for(int i=0;i<nq;i++)
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].val);
        
    sort(q,q+nq);
    
    int ptr = 0, qtd = 0;
    
    dp[0] = n+1;
    
    for(int i=1;i<=n;i++){
        
        while(ptr < nq && q[ptr].l == i){
            for(int j=n;j>=q[ptr].val;j--){
                dp[j] = max(dp[j], min(q[ptr].r,dp[j-q[ptr].val]));
                debug("dp[%d] := %d %d %d\n",j,dp[j],q[ptr].r,dp[j-q[ptr].val]);
                if(dp[j] >= i && ans[j] == 0)
                    ans[j] = 1, qtd++;
            }
            ptr++;
        }
    }
    
    printf("%d\n",qtd);
    for(int i=1;i<=n;i++)
        if(ans[i])
            printf("%d ",i);

    
}