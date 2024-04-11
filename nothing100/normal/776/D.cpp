#include<bits/stdc++.h>
#define LL long long
#define mo 1594323
using namespace std;
int n,m,r[200010],wh[200010][2],tot[200010],f[200010],bo;
void debug(){
    for (int i=2;i<2*m+2;i++) printf("%d ",f[i]);
    printf("\n");
}
int get(int x){
    if (!f[x]) return x;
    f[x]=get(f[x]);
    return f[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&r[i]);
    int o,p;
    for (int i=1;i<=m;i++){
        scanf("%d",&o);
        for (int j=0;j<o;j++){
            scanf("%d",&p);
            wh[p][tot[p]++]=i;
        }
    }
    for (int i=1;i<=n;i++){
        if (r[i]){
            o=get(2*wh[i][0]);
            p=get(2*wh[i][1]);
            if (o!=p) f[o]=p;
            o=get(2*wh[i][0]+1);
            p=get(2*wh[i][1]+1);
            if (o!=p) f[o]=p;
        }
        else{
            o=get(2*wh[i][0]);
            p=get(2*wh[i][1]+1);
            if (o!=p) f[o]=p;
            o=get(2*wh[i][0]+1);
            p=get(2*wh[i][1]);
            if (o!=p) f[o]=p;
        }
    }
    for (int i=1;i<=m;i++){
        o=get(2*i);
        p=get(2*i+1);
        if (o==p){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}