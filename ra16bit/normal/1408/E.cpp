#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int num,m,n,i,j,len,x,y,a[100100],b[100100],p[200200],rk[200200];
pii all[200200];
long long r;
int count(const pii& x) {
  return a[x.first]+b[x.second];
}
bool cmp(const pii& x, const pii& y) {
  return count(x)>count(y);
}
int fs(int x) {
  if (p[x]!=x) p[x]=fs(p[x]);
  return p[x];
}
int main() {
  scanf("%d%d",&m,&n);
  for (i=0; i<m; i++) scanf("%d",&a[i]);
  for (j=0; j<n; j++) scanf("%d",&b[j]);
  for (i=0; i<m; i++) {
    scanf("%d",&len);
    for (j=0; j<len; j++) {
      scanf("%d",&x);
      all[num++]={i,x-1};
    }
  }
  for (i=0; i<n+m; i++) p[i]=i;
  sort(all,all+num,cmp);
  for (i=0; i<num; i++) {
    x=fs(all[i].second);
    y=fs(n+all[i].first);
    if (x!=y) {
      if (rk[x]<rk[y]) {
        p[x]=y;
      } else {
        p[y]=x;
        if (rk[x]==rk[y]) ++rk[x];
      }
    } else r+=count(all[i]);
  }
  printf("%I64d\n",r);
  return 0;
}