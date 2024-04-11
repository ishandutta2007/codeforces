#include<bits/stdc++.h>
using namespace std;
int ma[2][500][500][8],bo[500][500],n,ans;
int main(){
    scanf("%d",&n);
    int fx[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    ma[0][250][250][0]=1;
    for (int w=0;w<n;w++){
        int tmp,now=w&1,nex=now^1;
        scanf("%d",&tmp);
        for (int i=0;i<500;i++)
        for (int j=0;j<500;j++)
        for (int k=0;k<8;k++)
        if (ma[now][i][j][k]){
            ma[now][i][j][k]=0;
            for (int h=1;h<=tmp;h++)
            if (!bo[i+fx[k][0]*h][j+fx[k][1]*h]){
                ans++;
                bo[i+fx[k][0]*h][j+fx[k][1]*h]=1;
            }
            ma[nex][i+fx[k][0]*tmp][j+fx[k][1]*tmp][(k+7)%8]=1;
            ma[nex][i+fx[k][0]*tmp][j+fx[k][1]*tmp][(k+1)%8]=1;
        }
    }
    printf("%d\n",ans);
}