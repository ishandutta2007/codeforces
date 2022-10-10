#include <bits/stdc++.h>
using namespace std;
int i,cur,ax[5],ay[5],bx[5],by[5],axn,axm,ayn,aym,bxn,bxm,byn,bym;
bool q;
bool insp(int w, int l, int r) {
  return w>=l && w<=r;
}
bool ins(int ax, int ay, int bx, int by, int x, int l, int r) {
  if (ax>bx) { swap(ax,bx); swap(ay,by); }
  if (ax>x || bx<x) return false;
  int A=by-ay;
  int B=ax-bx;
  int C=-ax*A-ay*B;
  return -C-A*x>=min(l*B,r*B) && -C-A*x<=max(l*B,r*B);
}
int main() {
  for (i=0; i<4; i++) {
    scanf("%d%d",&ax[i],&ay[i]);
    if (i==0) {
      axn=axm=ax[i];
      ayn=aym=ay[i];
    } else {
      axn=min(axn,ax[i]);
      axm=max(axm,ax[i]);
      ayn=min(ayn,ay[i]);
      aym=max(aym,ay[i]);
    }
  }
  for (i=0; i<4; i++) {
    scanf("%d%d",&bx[i],&by[i]);
    if (insp(bx[i],axn,axm) && insp(by[i],ayn,aym)) q=true;
  }
  bx[4]=bx[0];
  by[4]=by[0];
  for (i=0; i<4; i++) {
    if (ins(bx[i],by[i],bx[i+1],by[i+1],axn,ayn,aym)) q=true;
    if (ins(bx[i],by[i],bx[i+1],by[i+1],axm,ayn,aym)) q=true;
    if (ins(by[i],bx[i],by[i+1],bx[i+1],ayn,axn,axm)) q=true;
    if (ins(by[i],bx[i],by[i+1],bx[i+1],aym,axn,axm)) q=true;
  }
  for (i=0; i<4; i++) {
    cur=bx[i]+by[i];
    bx[i]-=by[i];
    by[i]=cur;
    if (i==0) {
      bxn=bxm=bx[i];
      byn=bym=by[i];
    } else {
      bxn=min(bxn,bx[i]);
      bxm=max(bxm,bx[i]);
      byn=min(byn,by[i]);
      bym=max(bym,by[i]);
    }
  }
  for (i=0; i<4; i++) {
    cur=ax[i]+ay[i];
    ax[i]-=ay[i];
    ay[i]=cur;
    if (insp(ax[i],bxn,bxm) && insp(ay[i],byn,bym)) q=true;
  }
  ax[4]=ax[0];
  ay[4]=ay[0];
  for (i=0; i<4; i++) {
    if (ins(ax[i],ay[i],ax[i+1],ay[i+1],bxn,byn,bym)) q=true;
    if (ins(ax[i],ay[i],ax[i+1],ay[i+1],bxm,byn,bym)) q=true;
    if (ins(ay[i],ax[i],ay[i+1],ax[i+1],byn,bxn,bxm)) q=true;
    if (ins(ay[i],ax[i],ay[i+1],ax[i+1],bym,bxn,bxm)) q=true;
  }
  puts(q?"YES":"NO");
  return 0;
}