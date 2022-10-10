#include <bits/stdc++.h>
using namespace std;
const int MX=1010;
int n,m,i,j,ans,a[MX],e[MX],k[MX],rx[MX*MX],ry[MX*MX];;
bool cmpup(int i, int j) {
  if (a[i]!=a[j]) return a[i]<a[j];
  return i<j;
}
bool cmp(int i, int j) { return a[i]>a[j]; }
void makeswp(int i, int j) {
  rx[ans]=i+1;
  ry[ans++]=j+1;
  swap(a[i],a[j]);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    k[i]=i;
  }
  sort(k,k+n,cmpup);
  for (i=0; i<n; i++) a[k[i]]=i;
  for (i=0; i<n; i++) {
    for (m=0, j=i+1; j<n; j++) if (a[j]<a[i]) k[m++]=j;
    sort(k,k+m,cmp);
    for (j=0; j<m; j++) makeswp(i,k[j]);
  }
  printf("%d\n",ans);
  for (i=0; i<ans; i++) printf("%d %d\n",rx[i],ry[i]);
  return 0;
}