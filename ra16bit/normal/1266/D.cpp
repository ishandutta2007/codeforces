#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,i,j,x,y;
long long v[MX],z;
vector<int> a,b,rx,ry;
vector<long long> rz;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%I64d",&x,&y,&z);
    v[x]+=z;
    v[y]-=z;
  }
  for (i=1; i<=n; i++) if (v[i]>0) a.push_back(i); else if (v[i]<0) b.push_back(i);
  for (i=j=0; i<a.size() && j<b.size(); ) {
    z=min(v[a[i]],-v[b[j]]);
    rx.push_back(a[i]);
    ry.push_back(b[j]);
    rz.push_back(z);
    if ((v[a[i]]-=z)==0) i++;
    if ((v[b[j]]+=z)==0) j++;
  }
  printf("%d\n",int(rx.size()));
  for (i=0; i<rx.size(); i++) printf("%d %d %I64d\n",rx[i],ry[i],rz[i]);
  return 0;
}