#include <stdio.h>
#include <stdlib.h>
#define MAXN 10
int v1[MAXN],v2[MAXN];
int main(){
   // FILE*fi,*fout;
    long long p1,p2,nr1,nr2;
    int i,n,m,j,bx,by;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    scanf("%d%d" ,&n,&bx);
    for(i=0;i<n;i++)
       scanf("%d" ,&v1[i]);
    scanf("%d%d" ,&m,&by);
    for(i=0;i<m;i++)
       scanf("%d" ,&v2[i]);
    p1=p2=1;
    for(i=0;i<n-1;i++)
       p1=p1*bx;
    for(i=0;i<m-1;i++)
       p2=p2*by;
    nr1=nr2=0;
    for(i=0;i<n;i++){
        nr1=nr1+v1[i]*p1;
        p1/=bx;
    }
    for(j=0;j<m;j++){
        nr2=nr2+v2[j]*p2;
        p2/=by;
    }
    if(nr1==nr2)
       printf("=");
    if(nr1>nr2)
      printf(">");
    if(nr1<nr2)
       printf("<");
    //fclose(fi);
    //fclose(fout);
    return 0;
}