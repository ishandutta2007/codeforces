#include <bits/stdc++.h>
using namespace std;
int t,n,le,ri,c,i,mn,mx,cmn,cmx,cw,cur;
bool was;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%d%d%d",&le,&ri,&c);
    mn=le; cmn=c;
    mx=ri; cmx=c;
    was=true; cw=c;
    printf("%d\n",c);
    for (i=1; i<n; i++) {
      scanf("%d%d%d",&le,&ri,&c);
      if (le<mn) {
        mn=le; cmn=c; was=false;
      } else if (le==mn && c<cmn) { mn=le; cmn=c; }
      if (ri>mx) {
        mx=ri; cmx=c; was=false;
      } else if (ri==mx && c<cmx) { mx=ri; cmx=c; }
      if (le==mn && ri==mx) {
        if (was) cw=min(cw,c); else { cw=c; was=true; }
      }
      cur=cmn+cmx;
      if (was && cw<cur) cur=cw;
      printf("%d\n",cur);
    }
  }
  return 0;
}