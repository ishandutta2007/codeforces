#include<stdio.h>
char in[110][110];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j,k,c=0;
    for(i=0;i<n;i++)scanf("%s",in[i]);
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(in[i][j]=='W'){
    for(k=0;k<4;k++){
        int ii=i+dx[k],jj=j+dy[k];
        if(ii>=0&&ii<n&&jj>=0&&jj<m&&in[ii][jj]=='P')break;
    }
    if(k<4)c++;
    }
    printf("%d\n",c);
}