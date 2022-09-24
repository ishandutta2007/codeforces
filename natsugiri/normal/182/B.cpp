#include<cstdio>

int n, d, t;

int main(){
  int r=0;
  scanf("%d%d", &d, &n);
  
  for(int i=1; i<n; i++){
    scanf("%d", &t);
    r+=d-t;
  }
  
  printf("%d\n",r);
  return 0;
}