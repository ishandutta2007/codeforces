#include <stdio.h>
int n,i,j,k,m,u[100100],r[62],as[62];
long long x,cur,all,a[100100],b[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d",&a[i]);
    x=x^a[i];
    u[i]=-1;
  }
  for (i=60; i>=0; i--) {
    cur=(1LL<<i); r[i]=-1;
    if (x&cur) continue;
    for (j=0; j<n; j++) if (u[j]==-1 && (a[j]&cur)) break;
    if (j>=n) continue;
    u[j]=i;
    r[i]=j;
    as[m++]=j;
    b[j]^=cur;
    for (k=j+1; k<n; k++) if (u[k]==-1 && (a[k]&cur)) {
      a[k]^=a[j];
      b[k]^=b[j];
    }
  }
  for (i=60; i>=0; i--) {
    cur=(1LL<<i);
    if ((x&cur)==0) continue;
    for (j=0; j<n; j++) if (u[j]==-1 && (a[j]&cur)) break;
    if (j>=n) continue;
    u[j]=i;
    r[i]=j;
    as[m++]=j;
    b[j]^=cur;
    for (k=j+1; k<n; k++) if (u[k]==-1 && (a[k]&cur)) {
      a[k]^=a[j];
      b[k]^=b[j];
    }
  }
  for (i=m-1; i>=0; i--) {
    j=as[i];
    for (k=0; k<=60; k++) if ((a[j]&(1LL<<k)) && u[j]!=k && r[k]!=-1) {
      a[j]^=a[r[k]];
      b[j]^=b[r[k]];
    }
    all^=b[j];
  }
  for (i=0; i<n; i++) printf("%d%c",(u[i]>=0 && (all&(1LL<<u[i])))?2:1,(i==n-1)?'\n':' ');
  return 0;
}