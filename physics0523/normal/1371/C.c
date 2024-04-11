#include<stdio.h>

int main(){
  long long t,a,b,n,m,k;
  scanf("%lld",&t);
  while(t>0){
    t--;
    scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
    if(a>b){k=a;a=b;b=k;}
    if(a<m){printf("No\n");continue;}
    if(a+b<n+m){printf("No\n");continue;}
    printf("Yes\n");
  }
}