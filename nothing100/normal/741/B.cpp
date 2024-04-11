#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
vector<int> v[1010];
int n,m,w,f[1010],a[1010],b[1010],dp[1010],suma[1010],sumb[1010];
int get(int x){
    if (!f[x]) return x;
    f[x]=get(f[x]);
    return f[x];
}
int main(){
    scanf("%d%d%d",&n,&m,&w);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=0;i<m;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        o=get(o);
        p=get(p);
        if (o!=p) f[o]=p;
    }
    for (int i=1;i<=n;i++){
        int o=get(i);
        v[o].push_back(i);
        suma[o]+=a[i];
        sumb[o]+=b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=w;j;j--){
            if (j>=suma[i]) dp[j]=max(dp[j],dp[j-suma[i]]+sumb[i]);
            for (int k=0;k<v[i].size();k++) if (j>=a[v[i][k]]) dp[j]=max(dp[j],dp[j-a[v[i][k]]]+b[v[i][k]]);
        }
    }
    printf("%d\n",dp[w]);
    return 0;
}