#include<bits/stdc++.h>
using namespace std;
bitset<7000> ys[7070],fy[7070],f[100010];
int n,q,miu[7070];
int main(){
    for (int i=1;i<=7000;i++){
        for (int j=1;j*i<=7000;j++){
            ys[j*i].set(i-1);
        }
    }
    for (int i=1;i<=7000;i++){
        miu[i]=1;
        for (int j=2;j*j<=i;j++)
        if (i%(j*j)==0) miu[i]=0;
    }
    for (int i=1;i<=7000;i++)
        for (int j=1;j*i<=7000;j++){
            fy[i].set(j*i-1,miu[j]);
        }
    scanf("%d%d",&n,&q);
    for (int i=0;i<q;i++){
        int o,p,t,q;
        scanf("%d",&o);
        if (o==1){
            scanf("%d%d",&p,&t);
            f[p]=ys[t];
        }
        else if (o==2){
            scanf("%d%d%d",&p,&t,&q);
            f[p]=f[t]^f[q];
        }
        else if (o==3){
            scanf("%d%d%d",&p,&t,&q);
            f[p]=f[t]&f[q];
        }
        else if (o==4){
            scanf("%d%d",&p,&t);
            printf("%d",(f[p]&fy[t]).count()&1);
        }
    }
}