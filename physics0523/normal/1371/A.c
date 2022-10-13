#include<stdio.h>

int main(){
  long long n,t;
  scanf("%lld",&t);
  while(t>0){
    t--;
    scanf("%lld",&n);
    if(n%2){printf("%lld\n",(n/2)+1);}
    else{printf("%lld\n",n/2);}
  }
  return 0;
}