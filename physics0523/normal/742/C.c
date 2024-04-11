#include<stdio.h>

long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}

int main(){
  long long n,a[128],res=1;
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}
  for(int i=1;i<=n;i++){
    long long len=1,pt=a[i];
    while(len<1000){
      if(pt==i){break;}
      len++;
      pt=a[pt];
    }
    if(len==1000){puts("-1");return 0;}
    if(len%2==0){len/=2;}
    res=lllcm(len,res);
  }
  printf("%lld\n",res);
}