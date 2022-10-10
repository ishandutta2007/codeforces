#include <bits/stdc++.h>
using namespace std;
int n,i,xa,ya,xb,yb,rx,ry,vx,vy;
long long lp,lq,rp,rq;
bool was;
void upd(int pl, int pr, int q) {
  if (q<0) { q=-q; pl=-pl; pr=-pr; }
  if (pl>pr) swap(pl,pr);
  if (!was) {
    was=true;
    lp=max(0,pl); lq=q;
    rp=pr;        rq=q;
    return;
  }
  if (pl*lq>lp*q) { lp=pl; lq=q; }
  if (pr*rq<rp*q) { rp=pr; rq=q; }
}
int main() {
  scanf("%d",&n);
  scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
  for (i=0; i<n; i++) {
    scanf("%d%d%d%d",&rx,&ry,&vx,&vy);
    if (vx==0 && vy==0) {
      if (rx<=xa || rx>=xb || ry<=ya || ry>=yb) { puts("-1"); return 0; }
    } else if (vx==0) {
      if (rx<=xa || rx>=xb) { puts("-1"); return 0; }
      upd(ya-ry,yb-ry,vy);
    } else if (vy==0) {
      if (ry<=ya || ry>=yb) { puts("-1"); return 0; }
      upd(xa-rx,xb-rx,vx);
    } else {
      upd(xa-rx,xb-rx,vx);
      upd(ya-ry,yb-ry,vy);
    }
  }
  if (!was) { puts("0"); return 0; }
  if (lp*rq>=rp*lq) { puts("-1"); return 0; } 
  printf("%.10lf\n",double(lp)/lq);
  return 0;
}