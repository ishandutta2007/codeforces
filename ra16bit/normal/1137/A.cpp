#include <bits/stdc++.h>
using namespace std;
int n,m,ii,i,j,p,cur,a[1010][1010],ha[1010][1010],hb[1010][1010],va[1010][1010],vb[1010][1010],k[1010];
bool cmpi(int x, int y) {
  return a[i][x]<a[i][y];
}
bool cmpj(int x, int y) {
  return a[x][j]<a[y][j];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) k[i]=i;
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) scanf("%d",&a[i][j]);
    sort(k,k+m,cmpi);
    for (p=-1, cur=ii=0; ii<m; ii++) {
      j=k[ii];
      if (p==-1 || a[i][p]!=a[i][j]) cur++;
      ha[i][j]=cur-1;
      p=j;
    }
    reverse(k,k+m);
    for (p=-1, cur=ii=0; ii<m; ii++) {
      j=k[ii];
      if (p==-1 || a[i][p]!=a[i][j]) cur++;
      hb[i][j]=cur-1;
      p=j;
    }
  }
  for (i=0; i<n; i++) k[i]=i;
  for (j=0; j<m; j++) {
    sort(k,k+n,cmpj);
    for (p=-1, cur=ii=0; ii<n; ii++) {
      i=k[ii];
      if (p==-1 || a[p][j]!=a[i][j]) cur++;
      va[i][j]=cur-1;
      p=i;
    }
    reverse(k,k+n);
    for (p=-1, cur=ii=0; ii<n; ii++) {
      i=k[ii];
      if (p==-1 || a[p][j]!=a[i][j]) cur++;
      vb[i][j]=cur-1;
      p=i;
    }
  }
  for (i=0; i<n; i++, puts("")) for (j=0; j<m; j++)
    printf("%d ",max(ha[i][j],va[i][j])+1+max(hb[i][j],vb[i][j]));
  return 0;
}