#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
int n,m,k,a[1010],f[1010],sum[1010],ans;
int get(int x){
    if (f[x]==0) return x;
    f[x]=get(f[x]);
    return f[x];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<k;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) sum[i]=1;
    for (int i=0;i<m;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        o=get(o);
        p=get(p);
        if (o!=p){
            f[o]=p;
            sum[p]+=sum[o];
        }
    }
    int mx=0,wh=0,sy=n;
    for (int i=0;i<k;i++){
        int o=get(a[i]);
        sy-=sum[o];
        if (sum[o]>mx){
            mx=sum[o];
            wh=i;
        }
    }
    for (int i=0;i<k;i++){
        int o=get(a[i]);
        if (i!=wh) ans+=sum[o]*(sum[o]-1)/2;
        else ans+=(sum[o]+sy)*(sum[o]+sy-1)/2;
    }
    ans-=m;
    printf("%d\n",ans);
}