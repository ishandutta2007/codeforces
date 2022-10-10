#include <bits/stdc++.h>
using namespace std;
int i,j,x,z,m,a[2][2],c[2];
char s[2000200];
int main() {
  for (i=0; i<2; i++) for (j=0; j<2; j++) scanf("%d",&a[i][j]);
  for (i=0; i<2; i++) {
    for (j=1; j<=44800; j++) if (j*(j-1)==2*a[i][i]) break;
    if (j>44800) { puts("Impossible"); return 0; }
    c[i]=j;
  }
  if (a[0][1]==0 && a[1][0]==0) {
    if (c[0]>c[1]) {
      if (a[1][1]==0) for (i=0; i<c[0]; i++) putchar('0'); else puts("Impossible");
    } else {
      if (a[0][0]==0) for (i=0; i<c[1]; i++) putchar('1'); else puts("Impossible");
    }
    return 0;
  }
  if (c[0]*c[1]!=a[0][1]+a[1][0]) { puts("Impossible"); return 0; }
  x=a[0][1]/c[1];
  for (i=0; i<x; i++) s[m++]='0';
  for (i=0; i<c[1]; i++) {
    for (z=a[0][1]/(c[1]-i); x<z; x++) s[m++]='0';
    s[m++]='1';
    a[0][1]-=x;
  }
  for (; x<c[0]; x++) s[m++]='0';
  if (m==c[0]+c[1]) puts(s); else puts("Impossible");
  return 0;
}