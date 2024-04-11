#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=200200;
int n,m,s,t,i,p,cv,res,l,r,h,c[MX],v[MX],k[MX],a[MX];
long long d,cur;
bool cmp(int i, int j) {
  return v[i]<v[j];
}
int main() {
  scanf("%d%d%d%d",&m,&n,&s,&t);
  for (i=0; i<m; i++) {
    scanf("%d%d",&c[i],&v[i]);
    k[i]=i;
  }
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  if (s>t) { puts("-1"); return 0; }
  sort(a,a+n);
  sort(k,k+m,cmp);
  a[n]=s;
  k[m]=m;
  v[m]=2*s;
  l=0; r=m;
  while (l<r) {
    h=(l+r)/2;
    cv=v[k[h]];
    for (cur=p=i=0; i<=n; i++) {
      d=a[i]-p;
      if (d>cv) break;
      if (d*2<=cv) cur+=d; else cur+=3*d-cv;
      p=a[i];
    }
    if (i<=n || cur>t) l=h+1; else r=h;
  }
  cv=v[k[r]]; res=-1;
  for (i=0; i<m; i++) if (v[i]>=cv && (res==-1 || c[i]<res)) res=c[i];
  printf("%d\n",res);
  return 0;
}