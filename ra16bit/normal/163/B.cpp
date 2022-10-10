#include <cstdio>
#include <algorithm>
using namespace std;
int k,n,h,i,j,it,m[100100],v[100100],id[100100];
long double l,r,mid,eps=1e-8;
bool cmp(int i, int j) {
  return m[i]<m[j] || (m[i]==m[j] && v[i]<v[j]);
}
int main() {
  scanf("%d%d%d",&n,&k,&h);
  for (i=0; i<n; i++) { scanf("%d",&m[i]); id[i]=i; }
  for (i=0; i<n; i++) scanf("%d",&v[i]);
  sort(id,id+n,cmp);
  l=0; r=2e9;
  for (it=0; it<100; it++) {
    mid=(l+r)*0.5;
    for (i=0, j=1; i<n && j<=k; i++) if (j*h<v[id[i]]*mid+eps) j++;
    if (j>k) r=mid; else l=mid;
  }
  for (i=0, j=1; i<n && j<=k; i++) if (j*h<v[id[i]]*r+eps) {
    printf("%d",id[i]+1);
    if (++j>k) putchar('\n'); else putchar(' ');
  }
  return 0;
}