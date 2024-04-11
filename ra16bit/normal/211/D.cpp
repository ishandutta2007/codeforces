#include <stdio.h>
const int MX=1000100;
int i,n,m,t,l[MX],r[MX],a[MX],s[MX];
long long w[MX],ans[MX],tot,cur;
long double p,q;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    while (m>0 && a[i]<a[s[m]]) r[s[m--]]=i;
    s[++m]=i;
    cur+=a[i];
  }
  while (m>0) r[s[m--]]=n;
  for (i=n-1; i>=0; i--) {
    while (m>0 && a[i]<=a[s[m]]) l[s[m--]]=i;
    s[++m]=i;
  }
  while (m>0) l[s[m--]]=-1;
  for (i=0; i<n; i++) {
    w[i-l[i]]+=a[i];
    w[r[i]-i]+=a[i];
    w[r[i]-l[i]]-=a[i];
//    printf("%d: %d %d\n",i,l[i],r[i]);
  }
  for (i=0; i<n; i++) {
//  printf("%d = %d\n",i,int(w[i]));
    cur-=w[i];
    tot+=cur;
    ans[i]=tot;
  }
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d",&t);
    p=ans[--t];
    q=n-t;
    printf("%.15lf\n",double(p/q));
  }
  return 0;
}