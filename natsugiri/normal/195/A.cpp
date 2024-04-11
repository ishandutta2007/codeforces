#include<cstdio>

int main(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", (a*c+b-1)/b-c);
  return 0;
}