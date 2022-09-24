#include<cstdio>

#define MOD 1000000007
typedef long long LL;

LL powMod(LL x,int y,LL mod){
  if(y<1)return 1;
  if(y%2)return x*powMod(x,y-1,mod)%mod;
  return powMod(x*x%mod,y/2,mod);
}

int main(){
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  if(k==1 || k>n){
    printf("%d\n",(int)powMod(m,n,MOD));
  }else if(n==k){
    printf("%d\n",(int)powMod(m,(n+1)/2,MOD));
  }else{
    if(k%2){
      printf("%d\n",m*m);
    }else{
      printf("%d\n",m);
    }
  }
  return 0;
}