#include <bits/stdc++.h>
using namespace std;
const int MX=140140;
int n,i,mx,cur,add,a[MX],b[MX*2];
void upd(int i, int L, int R, int pos, int val) {
  if (L==R) {
    b[i]=max(b[i],val);
    return;
  }
  int h=(L+R)/2;
  if (pos<=h) upd(i*2,L,h,pos,val); else upd(i*2+1,h+1,R,pos,val);
  b[i]=max(b[i*2],b[i*2+1]);
}
int fnd(int i, int L, int R, int le, int ri) {
  if (le>ri) return 0;
  if (L==le && R==ri) return b[i];
  int h=(L+R)/2,cur=0;
  if (le<=h) cur=max(cur,fnd(i*2,L,h,le,min(ri,h)));
  if (ri>h) cur=max(cur,fnd(i*2+1,h+1,R,max(le,h+1),ri));
  return cur;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (i==0) {
      upd(1,0,n,0,1);
    } else {
      cur=fnd(1,0,n,a[i],a[i]);
      mx=max(fnd(1,0,n,0,a[i]-1),fnd(1,0,n,a[i]+1,n));
      cur=max(mx+1,cur)+add;
      if (a[i]!=a[i-1]) ++add;
      upd(1,0,n,a[i-1],cur-add);
    }
  }
  printf("%d\n",fnd(1,0,n,0,n)+add);
  return 0;
}