#include <stdio.h>
int n,m,a,b,c,i,j,ii,jj;
char c1,c2,r[111][111];
int main() {
  scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
  if (n%2==1 && m%2==1) { puts("IMPOSSIBLE"); return 0; }
  if (n*m>a*2+b*2+c*4) { puts("IMPOSSIBLE"); return 0; }
  if (n%2==1) {
    for (i=0; i<m; i++) if (i%4<2) r[n-1][i]='y'; else r[n-1][i]='z';
    a-=m/2;
    if (a<0) { puts("IMPOSSIBLE"); return 0; }
  }
  if (m%2==1) {
    for (i=0; i<n; i++) if (i%4<2) r[i][m-1]='y'; else r[i][m-1]='z';
    b-=n/2;
    if (b<0) { puts("IMPOSSIBLE"); return 0; }
  }
  for (i=0; 2*i+1<n; i++) for (j=0; 2*j+1<m; j++) {
    ii=i&1; jj=j&1;
    if (ii==0 && jj==0) { c1='a'; c2='b'; }
    if (ii==0 && jj==1) { c1='c'; c2='d'; }
    if (ii==1 && jj==0) { c1='e'; c2='f'; }
    if (ii==1 && jj==1) { c1='g'; c2='h'; }
    if (c>0) {
     r[2*i][2*j]=c1;
     r[2*i][2*j+1]=c1;
     r[2*i+1][2*j]=c1;
     r[2*i+1][2*j+1]=c1;
     c--;
   } else if (a>1) {
     r[2*i][2*j]=c1;
     r[2*i][2*j+1]=c1;
     r[2*i+1][2*j]=c2;
     r[2*i+1][2*j+1]=c2;
     a-=2;
   } else if (b>1) {
     r[2*i][2*j]=c1;
     r[2*i][2*j+1]=c2;
     r[2*i+1][2*j]=c1;
     r[2*i+1][2*j+1]=c2;
     b-=2;
   } else { puts("IMPOSSIBLE"); return 0; }
  }
  for (i=0; i<n; i++) puts(r[i]);
  return 0;
}