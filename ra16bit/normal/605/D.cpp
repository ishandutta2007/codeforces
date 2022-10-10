#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=100100,BS=300;
int n,i,j,x,y,z,cz,cur,fi,fr,q[MX],p[MX],pr[MX],a[MX],b[MX],c[MX],d[MX],k[MX],pk[MX],e[MX],cnt[MX];
vector<int> v;
bool cmpa(int i, int j) {
  if (a[i]!=a[j]) return a[i]<a[j];
  return b[i]<b[j];
}
bool cmpb(int i, int j) {
  if (b[i]!=b[j]) return b[i]<b[j];
  return a[i]<a[j];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    k[i]=i;
  }
  sort(k,k+n,cmpa);
  for (i=j=0; i<n; i+=BS, j++) {
    pk[j]=k[i];
    e[j]=i;
    cnt[j]=min(BS,n-i);
    sort(k+i,k+i+cnt[j],cmpb);
  }
  q[fi=0]=n; p[n]=1; fr=1;
  while (fi<fr) {
    if (q[fi]==n-1) {
    printf("%d\n",p[q[fi]]-1);
    x=q[fi];
    for (i=1; i<p[q[fi]]; i++) {
      v.push_back(x);
      x=pr[x];
    }
    for (i=0; i<v.size(); i++) printf("%d ",v[int(v.size())-1-i]+1);
    return 0;
    }
    int ee=q[fi];
    x=c[q[fi]];
    y=d[q[fi]];
    cz=p[q[fi++]]+1;
    for (i=j=0; i<n; i+=BS, j++) if (a[pk[j]]<=x) {
      bool wb=false;
      for (cur=e[j]; cur<i+cnt[j]; cur++) {
        z=k[cur];
        if (b[z]>y) break;
        if (p[z]==0) {
          if (a[z]>x) {
            wb=true;
          } else {
            p[z]=cz;
            pr[z]=ee;
            q[fr++]=z;
          }
        }
      }
      if (!wb) e[j]=cur;
    } else break;
  }
  puts("-1");
  return 0;
}