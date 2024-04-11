#include<cstdio>

int main(){
  int n,i;
  int a,x,y;
  scanf("%d%d%d",&a,&x,&y);
  if(y<0 || y%a==0){
    puts("-1");
    return 0;
  }
  y/=a;
  if(y==0 || y%2==1){
    if(x*2<=-a || a<=x*2){
      puts("-1");
      return 0;
    }
    if(y==0)puts("1");
    else{
      printf("%d\n",y/2*3+2);
    }
  }else{
    if(x<=-a || a<=x || x==0){
      puts("-1");
      return 0;
    }
    printf("%d\n",y/2*3+(x>0));
  }
  return 0;
}