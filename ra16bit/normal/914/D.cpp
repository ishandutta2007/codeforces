#include <bits/stdc++.h>
using namespace std;
int n,m,i,t,l,r,x,res,a[2200200],b[500500];
int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }
void init(int i, int L, int R) {
  if (L==R) {
    a[i]=b[L];
    return;
  }
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
  a[i]=gcd(a[i*2],a[i*2+1]);
}
int solve(int i, int L, int R, int l, int r) {
  int h=(L+R)/2,cur=0;
  if (L==l && R==r) {
    if (a[i]%x!=0) {
      if (L<R) {
        cur=solve(i*2,L,h,L,h);
        if (cur<2) cur+=solve(i*2+1,h+1,R,h+1,R);
      } else cur=1;
    }
  } else {
    if (l<=h) cur+=solve(i*2,L,h,l,min(r,h));
    if (r>h) cur+=solve(i*2+1,h+1,R,max(l,h+1),r);
  }
  return min(cur,2);
}
void modify(int i, int L, int R, int x, int v) {
  if (L==R) {
    a[i]=v;
    return;
  }
  int h=(L+R)/2;
  if (x<=h) modify(i*2,L,h,x,v); else modify(i*2+1,h+1,R,x,v);
  a[i]=gcd(a[i*2],a[i*2+1]);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&b[i]);
  init(1,1,n);
  scanf("%d",&m);
  while (m--) {
    scanf("%d%d%d",&t,&l,&r);
    if (t==1) {
      scanf("%d",&x);
      res=solve(1,1,n,l,r);
      puts((res<2)?"YES":"NO");
    } else modify(1,1,n,l,r);
  }
  return 0;
}