#include<bits/stdc++.h>
using namespace std;
int n,a[110],can[110],bef[110],ans,b[110][2];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) a[i]+=a[i-1];
    can[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<i;j++)
        if (can[j]&&(a[i]-a[j])){
            can[i]=1;
            bef[i]=j;
            break;
        }
    }
    if (can[n]){
        printf("YES\n");
        for (int i=n;i;i=bef[i]){
            b[++ans][0]=bef[i]+1;
            b[ans][1]=i;
        }
        printf("%d\n",ans);
        for (int i=ans;i;i--) printf("%d %d\n",b[i][0],b[i][1]);
    }
    else printf("NO\n");
}