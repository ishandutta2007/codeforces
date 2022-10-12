#include<stdio.h>

long long A110468[16]={-1, 1, 3, 40, 1260, 72576, 6652800, 889574400, 163459296000, 39520825344000, 12164510040883200};

int main(){
  long long n;
  scanf("%lld",&n);
  printf("%lld\n",A110468[n/2]);
  return 0;
}