#include <stdio.h>
int n,m,i,x,a[1100100],b[1100100],c[1100100],e[1100100];
long long mi[22],ri[22],cur[22],tot;
void msort(int l, int r, int d) {
  if (l+1==r) return;
  long long m=(l+r)/2;
  msort(l,m,d-1);
  msort(m,r,d-1);
  int p1=l,p2=m;
  for (int i=l; i<r; i++) if (p2>=r || (p1<m && p2<r && b[p1]<=b[p2])) e[i]=b[p1++]; else {
    mi[d]+=m-p1;
    e[i]=b[p2++];
  }
  for (int i=l; i<r; i++) b[i]=e[i];
}
void rsort(int l, int r, int d) {
  if (l+1==r) return;
  long long m=(l+r)/2;
  rsort(l,m,d-1);
  rsort(m,r,d-1);
  int p1=l,p2=m;
  for (int i=l; i<r; i++) if (p2>=r || (p1<m && p2<r && c[p1]>=c[p2])) e[i]=c[p1++]; else {
    ri[d]+=m-p1;
    e[i]=c[p2++];
  }
  for (int i=l; i<r; i++) c[i]=e[i];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<(1<<n); i++) { scanf("%d",&a[i]); b[i]=c[i]=a[i]; }
  msort(0,(1<<n),n);
  rsort(0,(1<<n),n);
  for (i=0; i<=n; i++) { cur[i]=mi[i]; tot+=mi[i]; }
  scanf("%d",&m);
  while (m--) {
    scanf("%d",&x);
    for (i=x; i>=0; i--) {
      tot-=cur[i];
      cur[i]=mi[i]+ri[i]-cur[i];
      tot+=cur[i];
    }
    printf("%I64d\n",tot);
  }
  return 0;
}