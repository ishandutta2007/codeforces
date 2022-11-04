#include <stdio.h>
#include <stdlib.h>
int va[100000],vb[100000];
int main(){
   // FILE*fi,*fout;
    int na,nb,k,m,i,j;
   // fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    scanf("%d%d%d%d" ,&na,&nb,&k,&m);
    for(i=0;i<na;i++)
       scanf("%d" ,&va[i]);
    for(i=0;i<nb;i++)
       scanf("%d" ,&vb[i]);
    if(va[k-1]<vb[nb-m])
        printf("YES");
    else
        printf("NO");
    //fclose(fi);
   // fclose(fout);
    return 0;
}