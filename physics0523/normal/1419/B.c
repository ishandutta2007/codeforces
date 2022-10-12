#include<stdio.h>

int main(){
  long long zk[32],el=1;
  zk[0]=1;
  for(int i=1;i<32;i++){
    el*=2;
    zk[i]=2*zk[i-1]+el*el;
  }
  long long t;
  scanf("%lld",&t);
  while(t>0){
    t--;
    long long x,res=0;
    scanf("%lld",&x);
    for(int i=0;i<32;i++){
      if(x<zk[i]){break;}
      x-=zk[i];
      res++;
    }
    printf("%lld\n",res);
  }
}