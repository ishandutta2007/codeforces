#include<stdio.h>

long long ask(long long p){
  printf("? %lld\n",p);
  fflush(stdout);
  long long res;
  scanf("%lld",&res);
  return res;
}

int main(){
  long long n,k;
  scanf("%lld%lld",&n,&k);
  long long pt=1;
  long long del;
  if((n%307)!=0){del=307;}
  if((n%311)!=0){del=311;}
  if((n%313)!=0){del=313;}
  if((n%317)!=0){del=317;}
  long long v;
  while(1){
    v=ask(pt);
    if(v!=k){break;}
    pt+=del;
    while(pt>n){pt-=n;}
  }
  while(1){
    if(v==k){
      printf("! %lld\n",pt);
      fflush(stdout);
      return 0;
    }
    if(v>k){pt+=(n-1);}
    else{pt++;}
    while(pt>n){pt-=n;}
    v=ask(pt);
  }
}