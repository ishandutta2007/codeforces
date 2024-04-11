#include <stdio.h>
int n,m,x,i,a[8],b[8];
double r,res;
void cnt(int l, int d, double s, double p) {
  if (l==n) {
    if (d*2>n) r+=p; else r+=(p*x)/(x+s);
    return;
  }
  if (b[l]>0) cnt(l+1,d+1,s,p*0.1*b[l]);
  if (b[l]<10) cnt(l+1,d,s+a[l],p*0.1*(10-b[l]));
}
void rec(int l, int c) {
  if (l==n) {
    r=0;
    cnt(0,0,0,1.0);
    if (r>res) res=r;
    return;
  }
  for (int i=0; i<=c && b[l]+i<=10; i++) {
    b[l]+=i; rec(l+1,c-i); b[l]-=i;
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&x);
  for (i=0; i<n; i++) { scanf("%d%d",&a[i],&b[i]); b[i]/=10; }
  rec(0,m);
  printf("%.8lf\n",res);
  return 0;
}