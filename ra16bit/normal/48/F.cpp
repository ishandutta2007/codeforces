#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int m,n,W,i,j,k,a[555555],b[555555],c[555555];
long long w[555555],rs;
double rq;
void solve(int l, int r, long long x) {
  if (l==r) {
    rs+=(x*c[b[l]])/w[b[l]];
    rq+=double((x*c[b[l]])%w[b[l]])/w[b[l]];
    return;
  }
  int i=l,j=r,k,h=b[(l+r)>>1];
  long long e,f;
  while (i<=j) {
    while (c[b[i]]*w[h]<c[h]*w[b[i]]) i++;
    while (c[b[j]]*w[h]>c[h]*w[b[j]]) j--;
    if (i<=j) { k=b[i]; b[i++]=b[j]; b[j--]=k; }
  }
  for (f=e=0, k=l; k<i; k++) {
    f+=w[b[k]];
    e+=c[b[k]];
    if (f>=x) break;
  }
  if (k==i) {
    rs+=e;
    solve(i,r,x-f);
  } else if (k>j) {
    f-=w[b[k]];
    e-=c[b[k]];
    rs+=e+((x-f)*c[b[k]])/w[b[k]];
    rq+=double(((x-f)*c[b[k]])%w[b[k]])/w[b[k]];
  } else solve(l,j,x);
}
int main() {
  srand(time(0));
  scanf("%d%d%d",&m,&n,&W);
  for (i=0; i<n; i++) { scanf("%I64d",&w[i]); b[i]=i; }
  for (i=0; i<n; i++) scanf("%d",&c[i]);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (j=0; j<m; j++) {
    if (j) for (i=0; i<n; i++) c[i]-=a[i];
    solve(0,n-1,W);
  }
  rs+=int(rq); rq-=int(rq);
  rq+=rs%10; rs/=10;
  if (rs!=0) printf("%I64d",rs);
  printf("%.11lf\n",rq);
  return 0;
}