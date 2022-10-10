#include <bits/stdc++.h>
using namespace std;
const int MX=277277,inf=1100100100;
struct Node {
  int mn,mx;
} b[MX*2];
int n,q,i,j,l,le,a[MX],mns[MX],mxs[MX],mns2[MX],mxs2[MX],mnt,mxt,mnt2,mxt2,ls[MX],gr[MX],wls[MX],wgr[MX],r[2][MX],best[2][MX];
void init(int i, int L, int R) {
  b[i].mx=0;
  b[i].mn=inf;
  if (L==R) return;
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
}
void updgr(int i, int L, int R, int pos, int v) {
  if (L==R) {
    b[i].mx=v;
    return;
  }
  int h=(L+R)/2;
  if (pos<=h) updgr(i*2,L,h,pos,v); else updgr(i*2+1,h+1,R,pos,v);
  b[i].mx=max(b[i*2].mx,b[i*2+1].mx);
}
void updls(int i, int L, int R, int pos, int v) {
  if (L==R) {
    b[i].mn=v;
    return;
  }
  int h=(L+R)/2;
  if (pos<=h) updls(i*2,L,h,pos,v); else updls(i*2+1,h+1,R,pos,v);
  b[i].mn=min(b[i*2].mn,b[i*2+1].mn);
}
int getgr(int i, int L, int R, int rgh, int x) {
  if (b[i].mx<x) return 0;
  if (L==R) return R;
  int h=(L+R)/2;
  if (rgh<=h) return getgr(i*2,L,h,rgh,x);
  int pos=getgr(i*2+1,h+1,R,rgh,x);
  return (pos==0)?getgr(i*2,L,h,h,x):pos;
}
int getls(int i, int L, int R, int rgh, int x) {
  if (b[i].mn>x) return 0;
  if (L==R) return R;
  int h=(L+R)/2;
  if (rgh<=h) return getls(i*2,L,h,rgh,x);
  int pos=getls(i*2+1,h+1,R,rgh,x);
  return (pos==0)?getls(i*2,L,h,h,x):pos;
}
int main() {
  scanf("%d%d",&n,&q);
  init(1,1,n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    while (mnt>0 && a[mns[mnt]]>=a[i]) --mnt;
    ls[i]=mns[mnt];
    mns[++mnt]=i;
    while (mxt>0 && a[mxs[mxt]]<=a[i]) --mxt;
    gr[i]=mxs[mxt];
    mxs[++mxt]=i;
    //r[2][i]=max(ls[i],gr[i]);
    if (ls[i]>1) {
      r[0][i]=getls(1,1,n,ls[i]-1,inf-1);
      r[1][i]=getgr(1,1,n,ls[i],a[i]);
    }
    if (gr[i]>1) {
      r[0][i]=max(r[0][i],getgr(1,1,n,gr[i]-1,1));
      r[1][i]=max(r[1][i],getls(1,1,n,gr[i],a[i]));
    }
    while (mnt2>0 && a[mns2[mnt2]]>a[i]) {
      j=mns2[mnt2];
      wls[j]=i;
      updls(1,1,n,j,a[j]);
      --mnt2;
    }
    mns2[++mnt2]=i;
    while (mxt2>0 && a[mxs2[mxt2]]<a[i]) {
      j=mxs2[mxt2];
      wgr[j]=i;
      updgr(1,1,n,j,a[j]);
      --mxt2;
    }
    mxs2[++mxt2]=i;
    for (j=0; j<2; j++) best[j][i]=(r[j][i]>r[j][best[j][i-1]])?i:best[j][i-1];
    //printf("%d: %d | %d %d | %d %d\n",i,a[i],ls[i],gr[i],r[0][i],r[1][i]);
  }
  while (q--) {
    scanf("%d%d",&l,&j); le=l;
    if (r[1][best[1][j]]>=le) {
      puts("4");
      i=best[1][j];
      l=r[1][i];
      if (ls[i]>l && a[ls[i]]<a[l] && wgr[l]>l && wgr[l]<i && a[wgr[l]]>a[i]) {
        printf("%d %d %d %d\n",l,min(ls[i],wgr[l]),max(ls[i],wgr[l]),i);
        continue;
      }
      if (gr[i]>l && a[gr[i]]>a[l] && wls[l]>l && wls[l]<i && a[wls[l]]<a[i]) {
        printf("%d %d %d %d\n",l,min(gr[i],wls[l]),max(gr[i],wls[l]),i);
        continue;
      }
    }
    if (r[0][best[0][j]]>=le) {
      puts("3");
      i=best[0][j];
      l=r[0][i];
      if (ls[i]>l && a[ls[i]]<a[l]) {
        printf("%d %d %d\n",l,ls[i],i);
        continue;
      }
      if (gr[i]>l && a[gr[i]]>a[l]) {
        printf("%d %d %d\n",l,gr[i],i);
        continue;
      }
      if (wls[l]>l && wls[l]<i && a[wls[l]]<a[i]) {
        printf("%d %d %d\n",l,wls[l],i);
        continue;
      }
      if (wgr[l]>l && wgr[l]<i && a[wgr[l]]>a[i]) {
        printf("%d %d %d\n",l,wgr[l],i);
        continue;
      }
      continue;
    }
    puts("0\n");
  }
  return 0;
}