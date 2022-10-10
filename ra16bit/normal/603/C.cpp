#include <stdio.h>
int n,k,i,a,r,f[100100];
int solve(int i) {
  if (i==1 || i==3) return 1;
  if (i==2 || i%2) return 0;
  bool u[3];
  u[0]=u[1]=u[2]=false;
  u[solve(i/2)]=true;
  u[solve(i-1)]=true;
  int r=0;
  for (; u[r]; r++);
  return r;  
}
int sa(int i) {
  if (i<=2) return i;
  return 1-(i&1);
}
int main() {
  scanf("%d%d",&n,&k);
  k&=1;
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    r^=k?solve(a):sa(a);
  }
  puts(r?"Kevin":"Nicky");
  return 0;
}