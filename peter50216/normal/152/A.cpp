#include<stdio.h>
char in[110][110];
int cc[110];
int main(){
    int i,j;
    int n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",in[i]);
    for(i=0;i<m;i++){
        int ma=-1;
        for(j=0;j<n;j++){
            if(in[j][i]>ma)ma=in[j][i];
        }
        for(j=0;j<n;j++){
            if(in[j][i]==ma)cc[j]=1;
        }
    }
    int aa=0;
    for(i=0;i<n;i++)if(cc[i])aa++;
    printf("%d\n",aa);
}