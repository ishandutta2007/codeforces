#include <cstdio>
#define MAXN 1000
int A[MAXN+1],B[MAXN+1];
inline int cauta(int nrp,int k,int n){
     int i,sum;
     sum=0;
     for(i=1;i<=n;i++)
         if(nrp*A[i]>B[i])
            sum=sum+nrp*A[i]-B[i];
     return (sum<=k);
}
int main(){
  //  FILE*fi,*fout;
    int n,k,i,rez,pas;
  //  fi=fopen("D.in" ,"r");
   // fout=fopen("D.out" ,"w");
    scanf("%d%d" ,&n,&k);
    for(i=1;i<=n;i++)
       scanf("%d" ,&A[i]);
    for(i=1;i<=n;i++)
       scanf("%d" ,&B[i]);
    rez=0;
    for(pas=1<<12;pas;pas>>=1)
       if(cauta(rez+pas,k,n)==1)
          rez+=pas;
    printf("%d" ,rez);
   // fclose(fi);
  //  fclose(fout);
    return 0;
}