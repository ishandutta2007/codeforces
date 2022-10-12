#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}
void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}

int ask(int x,int y){
  if(x==y){return 0;}
  printf("? %d %d\n",x,y);
  fflush(stdout);
  int v;
  scanf("%d",&v);
  return v;
}

int main(){
  int n;
  scanf("%d",&n);
  int a[16384];
  int res[16384];
  if(n==1){
    printf("! 1\n");
    fflush(stdout);
    return 0;
  }
  for(int i=1;i<=n;i++){a[i]=i;}
  for(int i=1;i<=n-1;i++){
    int xy=ask(a[i],a[i+1]);
    int yx=ask(a[i+1],a[i]);
    if(xy<yx){swap(&a[i],&a[i+1]);}
    res[a[i]]=max(xy,yx);
  }
  res[a[n]]=n;
  printf("!");
  for(int i=1;i<=n;i++){printf(" %d",res[i]);}
  fflush(stdout);
}