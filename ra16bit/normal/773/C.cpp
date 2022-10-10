#include <bits/stdc++.h>
using namespace std;
int n,i,j,lst,tot,c[44][2],d[44];
long long a;
bool was;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%lld",&a);
    for (j=0; j<=40; j++) if ((1LL<<j)<=a) lst=j;
    ++c[lst][int((1LL<<lst)==a)];
  }
  for (i=1; i<=c[0][1]; i++) {
    d[0]=i;
    for (j=1; j<=40; j++) d[j]=min(d[j-1],c[j][1]);
    tot=0;
    for (j=40; j>=0; j--) {
      tot+=c[j][0]+c[j][1]-d[j];
      if (tot>d[j]) break;
    }
    if (j<0) { was=true; printf("%d ",i); }
  }
  if (!was) puts("-1");
  return 0;
}