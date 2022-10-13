//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

unsigned long long lldsum(unsigned long long x){unsigned long long r=0;while(x){r+=(x%10);x/=10;}return r;}

int main(void){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    unsigned long long n,s,res=0;
    scanf("%llu%llu",&n,&s);
    if(lldsum(n)<=s){puts("0");continue;}
    while(1){
      unsigned long long del=1,m=n;
      while(m%10==0){del*=10;m/=10;}
      res+=del;n+=del;
      if(lldsum(n)<=s){break;}
    }
    printf("%llu\n",res);
  }
  return 0;
}