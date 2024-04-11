#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll dp[5050][5050], path[5050][5050], MOD=1e9+7;
ll a[5050], val[5050];
ll tree[10010];
int n, k;

void build(){
    for (int i=1;i<=n;i++){
        for (int j=0;j<k;j++) val[i]=(val[i]+dp[i][j]*path[i][j])%MOD;
        //printf("%lld ", val[i]);
    }
    //printf("\n");
    for (int i=1;i<=n;i++) tree[n-1+i]=(a[i]*val[i])%MOD;
    for (int i=n-1;i>0;i--) tree[i]=(tree[i<<1]+tree[i<<1|1])%MOD;
}

void update(int idx, int p){
    idx += n;
    for (tree[idx]=(val[idx-n+1]*p)%MOD;idx>1;idx>>=1) tree[idx>>1]=(tree[idx]+tree[idx^1])%MOD;
}

int main(){
    int q;
    scanf("%d %d %d", &n, &k, &q);
    k++;
    for (int i=1;i<=n;i++) scanf("%lld", a+i);
    for (int i=1;i<=n;i++){
        dp[i][0]=1;
        path[i][k-1]=1;
    }
    for (int j=1;j<k;j++){
        for (int i=1;i<=n;i++) dp[i][j]=(dp[i-1][j-1]+dp[i+1][j-1])%MOD;
    }
    for (int j=k-2;j>=0;j--){
        for (int i=1;i<=n;i++) path[i][j]=(path[i-1][j+1]+path[i+1][j+1])%MOD;
    }
    build();
    while(q--){
        int t, x;
        scanf("%d %d", &t, &x);
        update(t-1, x);
        printf("%lld\n", tree[1]);
    }
    return 0;
}