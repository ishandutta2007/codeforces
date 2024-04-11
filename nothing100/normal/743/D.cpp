#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
struct bian{
    int point,next;
}b[2*MAXN];
int tot,n,g[MAXN],num[MAXN],hav[MAXN];
long long ans[MAXN],ma[MAXN],sum[MAXN];
void build(int x,int y){
    b[++tot].point=y; b[tot].next=g[x]; g[x]=tot;
    b[++tot].point=x; b[tot].next=g[y]; g[y]=tot;
}
void dfs(int x,int y){
    int bo=0;
    ma[x]=ans[x]=-inf;
    sum[x]=num[x];
    for (int i=g[x];i;i=b[i].next)
    if (b[i].point!=y){
        bo++;
        dfs(b[i].point,x);
        if (hav[b[i].point]){
            hav[x]=1;
            ans[x]=max(ans[x],ans[b[i].point]);
        }
        if (bo>1){
            hav[x]=1;
            ans[x]=max(ans[x],ma[x]+ma[b[i].point]);
        }
        ma[x]=max(ma[x],ma[b[i].point]);
        sum[x]+=sum[b[i].point];
    }
    ma[x]=max(ma[x],sum[x]);
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&num[i]);
    for (int i=1;i<n;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        build(--o,--p);
    }
    dfs(0,-1);
    if (hav[0]) printf("%lld\n",ans[0]);
    else printf("Impossible\n");
}