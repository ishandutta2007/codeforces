#include<stdio.h>

int main(){
  long long n,l=1,r,t,res;
  scanf("%lld",&t);
  while(t>0){
    t--;
    res=0;
    scanf("%lld%lld",&n,&r);
    if(n<=l){printf("1\n");continue;}
    if(n<=r){r=n-1;res=1;}
    printf("%lld\n",res+((l+r)*(r-l+1))/2);
  }
  return 0;
}