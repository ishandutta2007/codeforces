#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,i,j,lst,cnt,a[MX],r[MX],x[MX],y[MX],st1[MX],st2[MX],top1,top2;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=j=n; i>0; i--) if (a[i]!=0) {
    r[i]=n-cnt;
    ++cnt;
    if (a[i]==3) {
      if (top2>0) {
        y[m]=st2[top2--];
      } else if (top1>0) {
        y[m]=st1[top1--];
      } else {
        puts("-1");
        return 0;
      }
      x[m++]=r[i];
      st2[++top2]=i;
    } else if (a[i]==2) {
      if (top1>0) {
        r[st1[top1]]=r[i];
        top1--;
      } else {
        puts("-1");
        return 0;
      }
      st2[++top2]=i;
    } else if (a[i]==1) st1[++top1]=i;
  }
  printf("%d\n",cnt+m);
  for (i=1; i<=n; i++) if (a[i]!=0) printf("%d %d\n",r[i],i);
  for (i=0; i<m; i++) printf("%d %d\n",x[i],y[i]);
  return 0;
}