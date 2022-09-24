#include<cstdio>

int main(){
  int n,c,k,l,m,d;
  scanf("%d%d%d%d%d",&k,&l,&m,&n,&d);
  c=0;
  for(;d;d--){
    if(!(d%k&&d%l&&d%m&&d%n))c++;
  }
  printf("%d\n",c);
  return 0;
}