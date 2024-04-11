#include <cstdio>
#include <cstdlib>
#define MAXN 200000
int v[MAXN],next[MAXN+1];
int main(){
  //  FILE*fi,*fout;
    int i,n;
    long long con;
   // fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    scanf("%d" ,&n);
    for(i=0;i<n;i++){
        scanf("%d" ,&v[i]);
        next[v[i]-1]=i+1;
    }
    con=0;
    for(i=1;i<n;i++)
        con=con+abs(next[i]-next[i-1]);
    printf("%I64d" ,con);
   // fclose(fi);
   // fclose(fout);
    return 0;
}