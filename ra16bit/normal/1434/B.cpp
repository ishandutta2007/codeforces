#include <bits/stdc++.h>
using namespace std;
const int MX=140140;
int n,num,i,j,x,b[MX*2],c[MX*2],e[MX*2],r[MX];
char s[7];
void init(int i, int L, int R) {
  if (L==R) {
    b[i]=1;
    return;
  }
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
}
int fnd(int i, int L, int R, int x) {
  if (L==R) return R;
  int h=(L+R)/2;
  if (c[i*2]>0 && b[i*2]<=x) return fnd(i*2,L,h,x);
  return fnd(i*2+1,h+1,R,x);
}
void mdfc(int i, int L, int R, int x, int v) {
  if (L==R) {
    c[i]+=v;
    return;
  }
  int h=(L+R)/2;
  if (x<=h) mdfc(i*2,L,h,x,v); else mdfc(i*2+1,h+1,R,x,v);
  c[i]=c[i*2]+c[i*2+1];
  if (c[i]>0) {
    if (c[i*2]>0) {
      b[i]=b[i*2];
      if (c[i*2+1]>0) b[i]=min(b[i],b[i*2+1]);
    } else b[i]=b[i*2+1];
  }
  b[i]=max(b[i],e[i]);
}
void mdfe(int i, int L, int R, int le, int ri, int v) {
  if (L==le && R==ri) {
    e[i]=max(e[i],v);
    b[i]=max(b[i],e[i]);
    return;
  }
  int h=(L+R)/2;
  if (le<=h) mdfe(i*2,L,h,le,min(ri,h),v);
  if (ri>h) mdfe(i*2+1,h+1,R,max(le,h+1),ri,v);
  c[i]=c[i*2]+c[i*2+1];
  if (c[i]>0) {
    if (c[i*2]>0) {
      b[i]=b[i*2];
      if (c[i*2+1]>0) b[i]=min(b[i],b[i*2+1]);
    } else b[i]=b[i*2+1];
  }
  b[i]=max(b[i],e[i]);
}
int main() {
  scanf("%d",&n);
  init(1,1,n);
  for (i=0; i<2*n; i++) {
    scanf("%s",s);
    if (s[0]=='-') {
      scanf("%d",&x);
      if (c[1]<=0 || b[1]>x) { puts("NO"); return 0; }
      j=fnd(1,1,n,x);
      r[j]=x;
      mdfc(1,1,n,j,-1);
      mdfe(1,1,n,1,num,x);
    } else {
      ++num;
      mdfc(1,1,n,num,1);
    }
  }
  puts("YES");
  for (i=1; i<=n; i++) printf("%d%c",r[i],(i==n)?'\n':' ');
  return 0;
}