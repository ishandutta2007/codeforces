#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,a[300300],b[100100][3],c[300300];
bool z[300300],q;
int main() {
  scanf("%d",&n);
  for (i=1; i<=3*n; i++) { scanf("%d",&a[i]); c[a[i]]=i; }
  for (i=0; i<n; i++) for (j=0; j<3; j++) scanf("%d",&b[i][j]);
  scanf("%d",&k);
  for (i=0; i<n; i++) {
    if (c[b[i][1]]<c[b[i][0]]) swap(b[i][1],b[i][0]);
    if (c[b[i][2]]<c[b[i][0]]) swap(b[i][2],b[i][0]);
  }
  for (i=0; i<n; i++) if (b[i][1]==k || b[i][2]==k) {
    for (j=1; j<=3*n; j++) if (j!=k) {
      if (q) putchar(' ');
      printf("%d",j);
      q=true;
    }
    return 0;
  }
  for (i=0; i<n; i++) {
    for (j=0; j<3; j++) z[b[i][j]]=true;
    if (b[i][0]==k) {
      if (b[i][1]>b[i][2]) swap(b[i][1],b[i][2]);
      for (j=b[i][2]+1; j<=3*n; j++) z[j]=false;
      for (j=1; j<=3*n; j++) if (j!=k && z[j]) {
        if (q) putchar(' ');
        printf("%d",j);
        q=true;
      }
      for (j=1; j<=3*n; j++) if (j!=k && (!z[j])) {
        if (q) putchar(' ');
        printf("%d",j);
        q=true;
      }
      break;
    }
  }
  return 0;
}