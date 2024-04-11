#include <bits/stdc++.h>
using namespace std;
int n,i,l,r,h,w=-1,a[200200];
long long cnt,nc,c,p,sum,st,ww,we,s[200200];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    a[i]*=2;
  }
  sort(a+1,a+n+1);
  for (i=1; i<=n; i++) s[i]=s[i-1]+a[i];
  for (i=1; i<=n; i++) {
    st=s[n]+s[i];
    l=1; r=min(i,n-i);
    while (l<r) {
      h=(l+r)/2;
      c=st-s[n-h]-s[i-h];
      p=st-s[n-h-1]-s[i-h-1];
      if (p*h<c*(h+1LL)) r=h; else l=h+1;
    }
    if (l==r) {
      c=st-s[n-r]-s[i-r];
      nc=2LL*r;
      we=(a[i]+a[n-r+1])/2;
      if (w==-1 || (sum-ww*cnt)*nc<(c-nc*we)*cnt) {
        sum=c; cnt=nc; w=i; ww=we;
      }
    }
    l=1; r=min(i-1,n-i);
    while (l<r) {
      h=(l+r)/2;
      c=st-s[n-h]-s[i-h-1];
      p=st-s[n-h-1]-s[i-h-2];
      if (p*(2LL*h+1)<c*(2LL*h+3)) r=h; else l=h+1;
    }
    if (l==r) {
      c=st-s[n-r]-s[i-r-1];
      nc=2LL*r+1;
      if (w==-1 || (sum-ww*cnt)*nc<(c-nc*a[i])*cnt) {
        sum=c; cnt=nc; w=i; ww=a[i];
      }
    }
  }
  if (w==-1) printf("1\n%d\n",a[1]/2); else {
    printf("%d\n",int(cnt));
    for (i=w-(cnt-1)/2; i<=w; i++) printf("%d ",a[i]/2);
    for (i=n-cnt/2+1; i<=n; i++) printf("%d ",a[i]/2);
  }
  return 0;
}