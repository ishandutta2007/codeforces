#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
int a[100010],b[100010];
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<m;i++){
        int o,p,t;
        scanf("%d%d%d",&o,&p,&t);
        if (o==1) b[cnt++]=p;
    }
    sort(a,a+n);
    sort(b,b+cnt);
    a[n]=1000000000;
    ans=1000000;
    int tail=0;
    for (int i=0;i<=n;i++){
        while (tail<cnt&&b[tail]<a[i]) tail++;
        ans=min(ans,i+cnt-tail);
    }
    printf("%d\n",ans);
}