#include <bits/stdc++.h>
using namespace std;
const int MX=140140;
struct Node {
  long long x[10];
  char nxt[10];
  bool need;
} a[MX*10];
int b[MX],mx,n,m,i,t,l,r,xfr,y;
long long j,res,cur[10],scur[10];
void init(int i, int l, int r) {
  for (int j=0; j<10; j++) a[i].nxt[j]=j;
  if (l==r) {
    b[l]=i;
    return;
  }
  init(i*2,l,(l+r)/2);
  init(i*2+1,(l+r)/2+1,r);
}
void recount(int i, int l, int r) {
  if (l==r) return;
  recount(i*2,l,(l+r)/2);
  recount(i*2+1,(l+r)/2+1,r);
  for (int j=0; j<10; j++) a[i].x[j]=a[i*2].x[j]+a[i*2+1].x[j];
}
void psh(int i, int L, int R) {
  if (L!=R) for (int k=i*2; k<=i*2+1; k++) {
    for (int j=0; j<10; j++) cur[j]=0;
    for (int j=0; j<10; j++) cur[a[i].nxt[j]]+=a[k].x[j];
    for (int j=0; j<10; j++) {
      a[k].x[j]=cur[j];
      a[k].nxt[j]=a[i].nxt[a[k].nxt[j]];
      a[k].need|=(a[k].nxt[j]!=j);
    }
  }
  a[i].need=false;
  for (int j=0; j<10; j++) a[i].nxt[j]=j;
}
void modify(int i, int L, int R, int l, int r) {
  if (a[i].need) psh(i,L,R);
  if (L==l && R==r) {
    if (a[i].x[xfr]>0 && xfr!=y) {
      a[i].x[y]+=a[i].x[xfr];
      a[i].x[xfr]=0;
      for (int j=0; j<10; j++) if (a[i].nxt[j]==xfr) {
        a[i].nxt[j]=y;
        a[i].need|=(L<R && j!=y);
      }
    }
    return;
  }
  int h=(L+R)/2;
  if (l<=h) modify(i*2,L,h,l,min(h,r));
  if (r>h) modify(i*2+1,h+1,R,max(h+1,l),r);
  for (int j=0; j<10; j++) a[i].x[j]=a[i*2].x[j]+a[i*2+1].x[j];
}
void fsum(int i, int L, int R, int l, int r) {
  if (a[i].need>0) psh(i,L,R);
  if (L==l && R==r) {
    for (int j=0; j<10; j++) scur[j]+=a[i].x[j];
    return;
  }
  int h=(L+R)/2;
  if (l<=h) fsum(i*2,L,h,l,min(h,r));
  if (r>h) fsum(i*2+1,h+1,R,max(h+1,l),r);
  for (int j=0; j<10; j++) a[i].x[j]=a[i*2].x[j]+a[i*2+1].x[j];
}
int main() {
  scanf("%d%d",&n,&m);
  init(1,1,n);
  for (i=1; i<=n; i++) {
    scanf("%d",&y);
    for (j=1; y>0; y/=10, j*=10) a[b[i]].x[y%10]+=j;
  }
  recount(1,1,n);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&t,&l,&r);
    if (t==1) {
      scanf("%d%d",&xfr,&y);
      modify(1,1,n,l,r);
    } else {
      for (int j=0; j<10; j++) scur[j]=0;
      fsum(1,1,n,l,r);
      for (int j=res=0; j<10; j++) res+=j*scur[j];
      printf("%lld\n",res);
    }
  }
  return 0;
}