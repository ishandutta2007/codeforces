#include <stdio.h>
struct node {
  int i,j;
  long long k;
  bool operator < (node& p) {
    return (k<p.k || (k==p.k && (i<p.i || (i==p.i && j<p.j))));
  }
} h[1000100],r[1000100],z;
int a[1010][1010],e1[1010][1010],e2[1010][1010],e3[1010][1010],e4[1010][1010],i,j,n,m,x,y,ii,jj,num,res;
long long s[1010][1010],c;
bool u[1010][1010];
void hUp(int i) {
  while (i>1 && h[i]<h[i/2]) {
    z=h[i]; h[i]=h[i/2]; h[i/2]=z; i/=2;
  }
}
void exMin() {
  h[1]=h[num--];
  int i=1,k;
  while (2*i<=num) {
    if (h[2*i]<h[i]) k=2*i; else k=i;
    if (2*i<num && h[2*i+1]<h[k]) k=2*i+1;
    if (i==k) break;
    z=h[i]; h[i]=h[k]; h[k]=z; i=k;
  }
}
int main() {
  scanf("%d%d%d%d",&n,&m,&x,&y);
  for (i=1; i<=n; i++) {
    ii=i%x;
    for (j=1; j<=m; j++) {
      jj=j%y;
      scanf("%d",&a[i][j]);
      s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
      e1[i][j]=a[i][j];
      if (jj!=1 && y>1 && e1[i][j-1]<e1[i][j]) e1[i][j]=e1[i][j-1];
      if (ii!=1 && x>1 && e1[i-1][j]<e1[i][j]) e1[i][j]=e1[i-1][j];
    }
    for (j=m; j>=1; j--) {
      jj=j%y;
      e2[i][j]=a[i][j];
      if (jj!=0 && j!=m && y>1 && e2[i][j+1]<e2[i][j]) e2[i][j]=e2[i][j+1];
      if (ii!=1 && x>1 && e2[i-1][j]<e2[i][j]) e2[i][j]=e2[i-1][j];
    }
  }
  for (i=n; i>=1; i--) {
    ii=i%x;
    for (j=1; j<=m; j++) {
      jj=j%y;
      e3[i][j]=a[i][j];
      if (y>1 && jj!=1 && e3[i][j-1]<e3[i][j]) e3[i][j]=e3[i][j-1];
      if (x>1 && ii!=0 && i!=n && e3[i+1][j]<e3[i][j]) e3[i][j]=e3[i+1][j];
    }
    for (j=m; j>=1; j--) {
      jj=j%y;
      e4[i][j]=a[i][j];
      if (y>1 && jj!=0 && j!=m && e4[i][j+1]<e4[i][j]) e4[i][j]=e4[i][j+1];
      if (x>1 && ii!=0 && i!=n && e4[i+1][j]<e4[i][j]) e4[i][j]=e4[i+1][j];
    }
  }
  for (i=1; i+x-1<=n; i++) for (j=1; j+y-1<=m; j++) {
    z.i=i; z.j=j; c=e4[i][j];
    if (e2[i+x-1][j]<c) c=e2[i+x-1][j];
    if (e3[i][j+y-1]<c) c=e3[i][j+y-1];
    if (e1[i+x-1][j+y-1]<c) c=e1[i+x-1][j+y-1];
    z.k=s[i+x-1][j+y-1]-s[i+x-1][j-1]-s[i-1][j+y-1]+s[i-1][j-1]-x*y*c;
    h[++num]=z;
    hUp(num);
  }
  while (num) {
    if (!u[h[1].i][h[1].j]) {
      r[res++]=h[1];
      ii=h[1].i-x+1; if (ii<1) ii=1;
      jj=h[1].j-y+1; if (jj<1) jj=1;
      for (i=ii; i<h[1].i+x; i++) for (j=jj; j<h[1].j+y; j++) {
      u[i][j]=true;
      }
    }
    exMin();
  }
  printf("%d\n",res);
  for (i=0; i<res; i++) printf("%d %d %I64d\n",r[i].i,r[i].j,r[i].k);
  return 0;
}