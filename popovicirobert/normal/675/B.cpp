#include <cstdio>


int main(){
 //  FILE*fi,*fout;
   long long sol,n,a,b,c,d,x13,x33,x31,i;
  // fi=fopen("B.in" ,"r");
  // fout=fopen("B.out" ,"w");
   scanf("%I64d%I64d%I64d%I64d%I64d" ,&n,&a,&b,&c,&d);
   sol=0;
   for(i=1;i<=n;i++){
       x13=i-c+b;
       x31=i-d+a;
       x33=i+a+b-c-d;
       if(x13>0&&x33>0&&x31>0&&x13<=n&&x33<=n&&x31<=n)
          sol++;
   }
   sol*=n;
   printf("%I64d" ,sol);
  // fclose(fi);
 //  fclose(fout);
   return 0;
}