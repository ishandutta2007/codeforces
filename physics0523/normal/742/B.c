#include<stdio.h>

long long p2(long long v){
  return v*(v-1);
}

int main(){
  int a[131072]={0},n,x;
  scanf("%d%d",&n,&x);
  for(int i=0;i<n;i++){
    int v;
    scanf("%d",&v);
    a[v]++;
  }
  long long res=0;
  for(int i=0;i<131072;i++){
    int tg=x^i;
    if(i==tg){res+=p2(a[tg]);}
    else{res+=((long long)a[i])*((long long)a[tg]);}
  }
  printf("%lld\n",res/2);
}