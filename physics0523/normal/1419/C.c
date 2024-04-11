#include<stdio.h>

int main(){
  long long t,n,x,a[524288];
  scanf("%lld",&t);
  while(t>0){
    t--;
    scanf("%lld%lld",&n,&x);
    for(int i=0;i<n;i++){scanf("%lld",&a[i]);}
    long long fl=1,cnt=0,sig=0;
    for(int i=0;i<n;i++){
      if(a[i]!=x){fl=0;}
      if(a[i]==x){cnt++;}
      sig+=a[i];
    }
    if(fl){puts("0");continue;}
    if(cnt!=0){puts("1");continue;}
    if(sig==x*n){puts("1");continue;}
    puts("2");
  }
  return 0;
}