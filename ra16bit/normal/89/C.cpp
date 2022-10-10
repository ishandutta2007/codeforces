#include <stdio.h>
int n,m,i,j,z,p,e,l[5005],r[5005],u[5005],d[5005],L[5005],R[5005],D[5005],U[5005],c,res,rc;
short a[5005][5005];
char s[5005][5005],t[5005];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=z=0; i<n; i++) for (j=0; j<m; j++) if (s[i][j]!='.') { a[i][j]=++z; t[z]=s[i][j]; }
  for (i=0; i<n; i++) {
    for (j=e=0; j<m; j++)  if (s[i][j]!='.') { L[a[i][j]]=e; e=a[i][j]; }
    e=0;
    for (j=m-1; j>=0; j--) if (s[i][j]!='.') { R[a[i][j]]=e; e=a[i][j]; }
  }
  for (j=0; j<m; j++) {
    for (i=e=0; i<n; i++)  if (s[i][j]!='.') { U[a[i][j]]=e; e=a[i][j]; }
    e=0;
    for (i=n-1; i>=0; i--) if (s[i][j]!='.') { D[a[i][j]]=e; e=a[i][j]; }
  }
  for (e=1; e<=z; e++) {
    for (i=1; i<=z; i++) { l[i]=L[i]; r[i]=R[i]; u[i]=U[i]; d[i]=D[i]; }
    for (c=0, p=e; p!=0; c++, p=j) {
      if (t[p]=='L') j=l[p];
      if (t[p]=='R') j=r[p];
      if (t[p]=='U') j=u[p];
      if (t[p]=='D') j=d[p];
      if (l[p]!=0) r[l[p]]=r[p];
      if (r[p]!=0) l[r[p]]=l[p];
      if (u[p]!=0) d[u[p]]=d[p];
      if (d[p]!=0) u[d[p]]=u[p];
    }
    if (c>res) { res=c; rc=0; }
    if (c==res) rc++;
  }
  printf("%d %d\n",res,rc);
  return 0;
}