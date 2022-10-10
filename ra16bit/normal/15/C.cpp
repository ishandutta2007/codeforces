#include <stdio.h>
int i,n;
bool z1,z2;
long long j,l,k,x,m,s,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d%I64d",&x,&m); x--; m=x+m;
    if ((m&3)==2 || (m&3)==1) z1=true; else z1=false;
    if ((x&3)==2 || (x&3)==1) z2=true; else z2=false;
    if (z1!=z2) r^=1;
    for (j=k=2; j<62; j++, k*=2) {
      if (((m&k)==k) && ((m&1LL)==0)) z1=true; else z1=false;
      if (((x&k)==k) && ((x&1LL)==0)) z2=true; else z2=false;
      if (z1!=z2) r^=k;
    }    
  }
  if (r==0) puts("bolik"); else puts("tolik");
  return 0;
}