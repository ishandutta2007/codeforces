#include <bits/stdc++.h>
using namespace std;
const int MX=525525;
struct Node { int mx,add,best; } b[MX*4];
int n,i,x,ri,z,w[MX],a[MX];
void init(int i, int L, int R) {
  if (L==R) {
    b[i].mx=a[L];
    return;
  }
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
  b[i].mx=max(b[i*2].mx,b[i*2+1].mx);
}
int findmax(int i, int L, int R, int l, int r) {
  if (L==l && R==r) return b[i].mx;
  int h=(L+R)/2,cur=0;
  if (l<=h) cur=max(cur,findmax(i*2,L,h,l,min(r,h)));
  if (r>h) cur=max(cur,findmax(i*2+1,h+1,R,max(h+1,l),r));
  return cur;
}
void rm(int i, int L, int R, int pos) {
  if (L==R) {
    b[i].mx=0;
    return;
  }
  int h=(L+R)/2;
  if (pos<=h) rm(i*2,L,h,pos); else rm(i*2+1,h+1,R,pos);
  b[i].mx=max(b[i*2].mx,b[i*2+1].mx);
}
void mdf(int i, int L, int R, int l, int r, int v) {
  if (L==l && R==r) {
    b[i].add+=v;
    b[i].best+=v;
    return;
  }
  int h=(L+R)/2;
  if (l<=h) mdf(i*2,L,h,l,min(r,h),v);
  if (r>h) mdf(i*2+1,h+1,R,max(h+1,l),r,v);
  b[i].best=max(b[i*2].best,b[i*2+1].best)+b[i].add;
}
int findlftpos(int i, int L, int R, int cur) {
  if (L==R) return R;
  cur+=b[i].add;
  int h=(L+R)/2;
  if (b[i*2].best+cur>0) return findlftpos(i*2,L,h,cur);
  return findlftpos(i*2+1,h+1,R,cur);
}
void add(int* s, int x) {
  for (; x<=n; x=(x<<1)-(x&(x-1))) s[x]++;
}
int fsum(int* s, int x) {
  int r=0;
  for (; x>0; x&=x-1) r+=s[x];
  return r;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    w[a[i]]=i;
  }
  init(1,1,n);
  printf("%d ",b[1].mx);
  for (i=1; i<n; i++) {
    scanf("%d",&x);
    mdf(1,1,n,x,n,1);
    ri=findlftpos(1,1,n,0);
    z=findmax(1,1,n,1,ri);
    rm(1,1,n,w[z]);
    //printf("ri=%d (z=%d w[z]=%d)\n",ri,z,w[z]);
    //for (int j=1; j<=n; j++) printf("%d ",aa[j]); puts("aa");
    mdf(1,1,n,w[z],n,-1);
    printf("%d ",b[1].mx);
  }
  return 0;
}