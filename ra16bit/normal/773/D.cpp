#include <bits/stdc++.h>
using namespace std;
int n,cnt,i,j,x,y;
long long a[2020*2020],d[2020],mn;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=i+1; j<n; j++, cnt++) {
    scanf("%lld",&a[cnt]);
    a[cnt]<<=11; a[cnt]+=i;
    a[cnt]<<=11; a[cnt]+=j;
  }
  sort(a,a+cnt);
  mn=(a[0]>>22);
  for (i=0; i<n; i++) d[i]=-1;
  for (i=0; i<cnt; i++) {
    x=(a[i]&2047); a[i]>>=11;
    y=(a[i]&2047); a[i]>>=11;
    a[i]-=mn;
    if (d[x]==-1) d[x]=a[i]*2;
    if (d[y]==-1) d[y]=a[i]*2;
    d[x]=min(d[x],d[y]+a[i]);
    d[y]=min(d[y],d[x]+a[i]);
  }
  for (i=0; i<n; i++) printf("%lld\n",mn*(n-1)+d[i]);
  return 0;
}