#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    long long n;
    scanf("%lld",&n);
    if(n==1){puts("0");continue;}
    long long res=0;
    for(long long i=1;i<=(n/2);i++){
      res+=8*i*i;
    }
    printf("%lld\n",res);
  }
  return 0;
}