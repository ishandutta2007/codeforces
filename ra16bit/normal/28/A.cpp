#include <stdio.h>
int x[555],y[555],a[555],b[555],n,m,i,j,d;
bool q1=true,q2=true,u1[555],u2[555];
int ab(int x) { return (x<0)?(-x):x; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
  for (i=0; i<m; i++) scanf("%d",&a[i]);
  d=ab(x[n-1]-x[0])+ab(x[1]-x[0])+ab(y[n-1]-y[0])+ab(y[1]-y[0]);
  for (j=0; j<m; j++) if (a[j]==d && (!u2[j])) {
     b[i]=j; u2[j]=true; break;
  }
  if (j==m) q2=false;
  for (i=1; i<n-1; i++) {
    d=ab(x[i-1]-x[i])+ab(x[i+1]-x[i])+ab(y[i-1]-y[i])+ab(y[i+1]-y[i]);
    if (i&1) {
      for (j=0; j<m; j++) if (a[j]==d && (!u1[j])) {
        b[i]=j; u1[j]=true; break;
      }
      if (j==m) q1=false;
    } else {
      for (j=0; j<m; j++) if (a[j]==d && (!u2[j])) {
        b[i]=j; u2[j]=true; break;
      }
      if (j==m) q2=false;
    }
  }
  d=ab(x[n-1]-x[n-2])+ab(x[n-1]-x[0])+ab(y[n-1]-y[0])+ab(y[n-1]-y[n-2]);
  if ((n-1)&1) {
    for (j=0; j<m; j++) if (a[j]==d && (!u1[j])) {
      b[i]=j; u1[j]=true; break;
    }
    if (j==m) q1=false;
  } else {
    for (j=0; j<m; j++) if (a[j]==d && (!u2[j])) {
      b[i]=j; u2[j]=true; break;
    }
    if (j==m) q2=false;
  }
  if (q1) {
    puts("YES");
    for (i=0; i<n; i++) {
      if (i) putchar(' ');
      if (i&1) printf("%d",b[i]+1); else printf("-1");
    }
  } else if (q2) {
    puts("YES");
    for (i=0; i<n; i++) {
      if (i) putchar(' ');
      if (i&1) printf("-1"); else printf("%d",b[i]+1);
    }
  } else puts("NO");
  return 0;
}