#include<stdio.h>
#define mod 1000000007

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

int main(){
  long long a=0,b=0,c=0,iv3=modular_inverse(3),k=1;
  int l;
  char s[524288];
  scanf("%d%s",&l,s);
  for(int i=0;i<l;i++){
    if(s[i]=='?'){k*=3;k%=mod;}
  }
  for(int i=0;i<l;i++){
    if(s[i]=='a'){a+=k;a%=mod;}
    if(s[i]=='b'){b+=a;b%=mod;}
    if(s[i]=='c'){c+=b;c%=mod;}
    if(s[i]=='?'){
      c+=b*iv3;c%=mod;
      b+=a*iv3;b%=mod;
      a+=k*iv3;a%=mod;
    }
  }
  printf("%lld\n",c);
  return 0;
}