#include <cstdio>
#include <algorithm>
using namespace std;
int n,N,i,j,l,r,h,res;
long long m,mx,LE,a[525525],b[100100],c[100100],le[525525],ri[525525];
long double cur;
void rec(int l, long long s) {
  if (l>0) a[n++]=s;
  if (l<18) rec(l+1,s*10+4);
  if (l<18) rec(l+1,s*10+7);
}
int main() {
  rec(0,0);
  sort(a,a+n); N=n;
  scanf("%d%I64d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%I64d%I64d",&b[i],&c[i]);
    if (i==0 || c[i]-b[i]<mx) mx=c[i]-b[i];
  }
  sort(b,b+n);
  sort(c,c+n);
  for (i=j=0; i<N; i++) {
    if (i>0) {
      cur=a[i]-a[i-1];
      cur*=j;
      ri[i]=(cur<0.25e19)?ri[i-1]+(a[i]-a[i-1])*j:(m+10);
    }
    for (; j<n && c[j]<=a[i]; j++) {
      ri[i]+=a[i]-c[j];
      if (ri[i]>m+10) ri[i]=m+10;
    }
  }
  for (i=N-1, j=n-1; i>=0; i--) {
    if (i<N-1) {
      cur=a[i+1]-a[i];
      cur*=n-1-j;
      le[i]=(cur<0.25e19)?le[i+1]+(a[i+1]-a[i])*(n-1LL-j):(m+10);
    }
    for (; j>=0 && b[j]>=a[i]; j--) {
      le[i]+=b[j]-a[i];
      if (le[i]>m+10) le[i]=m+10;
    }
  }
  //for (i=0; i<10; i++) printf("%d: %d %d\n",i,int(le[i]),int(ri[i]));
  for (i=0; i<N; i++) {
  //printf("!%d = %I64d %I64d %I64d\n",i,le[i],ri[i],m);
    if (le[i]+ri[i]>m) continue;
    LE=le[i]; l=i; r=N-1;
    while (l<r) {
      h=(l+r)/2+1;
  //    printf("%d %d %d: %I64d %I64d\n",l,r,h,LE,ri[h]);
      if (a[h]-a[i]>mx || LE+ri[h]>m) r=h-1; else l=h;
    }
    if (r-i+1>res) res=r-i+1;
  }
  printf("%d\n",res);
  return 0;
}