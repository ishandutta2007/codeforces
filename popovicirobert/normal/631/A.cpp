#include <cstdio>
long long a[1001],b[1001];
int main(){
   // FILE*fi,*fout;
    int i,n,j;
    long long max,x;
    //fi=fopen("A.in" ,"r");
   // fout=fopen("A.out" ,"w");
    scanf("%d" ,&n);
    for(i=1;i<=n;i++){
       scanf("%I64d" ,&x);
       a[i]=(a[i-1]|x);
    }
    for(i=1;i<=n;i++){
       scanf("%I64d" ,&x);
       b[i]=(b[i-1]|x);
    }
    printf("%I64d" ,a[n]+b[n]);
    //fclose(fi);
   // fclose(fout);
    return 0;
}