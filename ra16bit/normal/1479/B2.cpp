#include <bits/stdc++.h>
using namespace std;
const int MX=140140,inf=1000000;
int n,i,mn,cur,add,a[MX],b[MX*2];
void init(int i, int L, int R) {
  b[i]=inf;
  if (L==R) return;
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
}
void upd(int i, int L, int R, int pos, int val) {
  if (L==R) {
    b[i]=min(b[i],val);
    return;
  }
  int h=(L+R)/2;
  if (pos<=h) upd(i*2,L,h,pos,val); else upd(i*2+1,h+1,R,pos,val);
  b[i]=min(b[i*2],b[i*2+1]);
}
int fnd(int i, int L, int R, int le, int ri) {
  if (le>ri) return inf;
  if (L==le && R==ri) return b[i];
  int h=(L+R)/2,cur=inf;
  if (le<=h) cur=min(cur,fnd(i*2,L,h,le,min(ri,h)));
  if (ri>h) cur=min(cur,fnd(i*2+1,h+1,R,max(le,h+1),ri));
  return cur;
}
int main() {
  scanf("%d",&n);
  init(1,0,n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (i==0) {
      upd(1,0,n,0,1);
    } else {
      cur=fnd(1,0,n,a[i],a[i]);
      mn=min(fnd(1,0,n,0,a[i]-1),fnd(1,0,n,a[i]+1,n));
      cur=min(mn+1,cur)+add;
      if (a[i]!=a[i-1]) ++add;
      upd(1,0,n,a[i-1],cur-add);
    }
  }
  printf("%d\n",fnd(1,0,n,0,n)+add);
  return 0;
}