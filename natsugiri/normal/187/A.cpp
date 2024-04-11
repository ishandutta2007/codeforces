#include<cstdio>

int n;
int a[200010], b[200010];

int main(){

  scanf("%d", &n);
  for(int i=0; i<n; i++)scanf("%d", a+i);
  for(int i=0; i<n; i++)scanf("%d", b+i);
  
  int x, y;
  x=y=0;
  for(;x<n; x++){
    for(;y<n && a[x]!=b[y]; y++);
    if(y>=n)break;
  }
    
  
  printf("%d\n", n-x);
  return 0;
}