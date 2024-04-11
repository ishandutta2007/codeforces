#include <bits/stdc++.h>
using namespace std;
const int MX=140140;
int n,i,j,cur,pos,a[MX],k[MX],best[MX*2],nxt[MX*2],r[MX];
bool cmp(int i, int j) { return a[i]<a[j]; }
void add(int i, int L, int R, int x) {
  if (best[i]==0) best[i]=x; else best[i]=min(best[i],x);
  if (L==R) return;
  int mid=(L+R)/2;
  if (x<=mid) add(i*2,L,mid,x); else add(i*2+1,mid+1,R,x);
}
int fnd(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) return best[i];
  int mid=(L+R)/2,best=0;
  if (le<=mid) best=fnd(i*2,L,mid,le,min(mid,ri));
  if (ri>mid && best==0) best=fnd(i*2+1,mid+1,R,max(mid+1,le),ri);
  return best;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) { scanf("%d",&a[i]); k[i-1]=i; }
  sort(k,k+n,cmp);
  for (i=j=0; i<n; i++) {
    cur=a[k[i]];
    for (; a[k[j]]*2<cur; j++) add(1,1,n,k[j]);
    pos=fnd(1,1,n,k[i],n);
    if (pos==0) pos=fnd(1,1,n,1,k[i]);
    if (pos!=0) {
      if (pos<k[i]) pos+=n;
      nxt[k[i]]=pos;
      nxt[k[i]+n]=pos+n;
    }
  }
  cur=-1;
  for (i=2*n; i>0; i--) {
    if (nxt[i]) {
      if (cur==-1 || nxt[i]<cur) cur=nxt[i];
    }
    if (i<=n) r[i]=(cur==-1)?-1:(cur-i);
  }
  for (i=1; i<=n; i++) printf("%d%c",r[i],(i==n)?'\n':' ');
  return 0;
}