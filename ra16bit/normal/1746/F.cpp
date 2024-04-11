#include <bits/stdc++.h>
using namespace std;
const int MX=300100,BS=31;
int num,n,q,i,j,a[MX],tp[MX],x[MX],y[MX],z[MX],s[BS][MX];
bool ins[BS][MX*2];
map<int,int> all;
void add(int j, int i, int v) {
  for (; i<=n; i=(i<<1)-(i&(i-1))) s[j][i]+=v;
}
int sum(int j, int i) {
  int res=0;
  for (; i>0; i&=i-1) res+=s[j][i];
  return res;
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    auto it=all.find(a[i]);
    if (it==all.end()) {
      all[a[i]]=++num;
      a[i]=num;
    } else a[i]=it->second;
  }
  for (i=0; i<q; i++) {
    scanf("%d%d%d",&tp[i],&x[i],&y[i]);
    if (tp[i]==1) {
      auto it=all.find(y[i]);
      if (it==all.end()) {
        all[y[i]]=++num;
        y[i]=num;
      } else y[i]=it->second;
    } else scanf("%d",&z[i]);
  }
  for (j=0; j<BS; j++) {
    for (i=1; i<=num; i++) if (rng()&1) ins[j][i]=true;
    for (i=1; i<=n; i++) if (ins[j][a[i]]) add(j,i,1);
  }
  for (i=0; i<q; i++) if (tp[i]==1) {
    for (j=0; j<BS; j++) {
      if (ins[j][a[x[i]]]) add(j,x[i],-1);
      if (ins[j][y[i]]) add(j,x[i],1);
    }
    a[x[i]]=y[i];
  } else {
    for (j=0; j<BS; j++) if ((sum(j,y[i])-sum(j,x[i]-1))%z[i]) break;
    puts((j<BS)?"NO":"YES");
  }
  return 0;
}