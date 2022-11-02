#include<bits/stdc++.h>
using namespace std;
int x[3],y[3],tmp[10],ansx,ansy,ans,bo[1010][1010];
int main(){
    for (int i=0;i<3;i++)
        scanf("%d%d",&x[i],&y[i]);
    for (int i=0;i<3;i++) tmp[i]=x[i];
    sort(tmp,tmp+3);
    ansx=tmp[1];
    for (int i=0;i<3;i++) tmp[i]=y[i];
    sort(tmp,tmp+3);
    ansy=tmp[1];
    for (int i=0;i<3;i++) ans=ans+abs(x[i]-ansx)+abs(y[i]-ansy);
    ans++;
    printf("%d\n",ans);
    for (int i=tmp[0];i<=tmp[2];i++)
        bo[ansx][i]=1;
    for (int i=0;i<3;i++){
        while (x[i]<ansx){
            bo[x[i]][y[i]]=1;
            x[i]++;
        }
        while (x[i]>ansx){
            bo[x[i]][y[i]]=1;
            x[i]--;
        }
    }
    for (int i=0;i<=1000;i++)
    for (int j=0;j<=1000;j++)
    if (bo[i][j]) printf("%d %d\n",i,j);
}