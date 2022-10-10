#include <bits/stdc++.h>
using namespace std;
const int MX=1000100;
int t,pn,a,b,i,ii,j,x,y,ac,bc,A[MX],p[MX];
bool ok;
int main() {
  for (i=2; i<MX; i++) if (!A[i]) {
    p[pn++]=i;
    for (j=i; j<MX; j+=i) if (A[j]==0) A[j]=i;
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&a,&b);
    x=max(a,b); ok=true;
    for (ii=0; p[ii]*p[ii]*p[ii]<=x; ii++) {
      i=p[ii];
      if (a%i==0 && b%i==0) {
        for (ac=0; a%i==0; a/=i) ac++;
        for (bc=0; b%i==0; b/=i) bc++;
        y=2*ac-bc;
        if (y<0 || y%3!=0) { ok=false; break; }
        y/=3;
        x=ac-2*y;
        if (x<0) { ok=false; break; }
      } else if (a%i==0 || b%i==0) {
        ok=false;
        break;
      }
      x=max(a,b);
    }
    if (x>1) {
      if (a>b) {
        if (a!=1LL*b*b) ok=false;
      } else {
        if (b!=1LL*a*a) ok=false;
      }
    }
    puts(ok?"Yes":"No");
  }
  return 0;
}