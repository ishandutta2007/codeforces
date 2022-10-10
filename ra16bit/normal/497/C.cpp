#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int n,m,ii,i,j,x,ax[100100],ay[100100],ak[100100],bx[100100],by[100100],bz[100100],bk[100100],r[100100];
set<pair<int,int> > c;
set<pair<int,int> >::iterator it;
bool cmpa(int i, int j) {
  if (ax[i]!=ax[j]) return ax[i]<ax[j];
  return ay[i]<ay[j];
}
bool cmpb(int i, int j) {
  if (bx[i]!=bx[j]) return bx[i]<bx[j];
  return by[i]<by[j];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&ax[i],&ay[i]);
    ak[i]=i;
  }
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&bx[i],&by[i],&bz[i]);
    bk[i]=i;
  }
  sort(ak,ak+n,cmpa);
  sort(bk,bk+m,cmpb);
  for (ii=j=0; ii<n; ii++) {
    i=ak[ii]; x=ax[i];
    for (; j<m && bx[bk[j]]<=x; j++) c.insert(make_pair(by[bk[j]],bk[j]));
    while (!c.empty()) {
      it=c.begin();
      if (it->first>=x) break;
      c.erase(it);
    }
    it=c.lower_bound(make_pair(ay[i],-1));
    if (it!=c.end()) {
      r[i]=it->second;
      if (--bz[r[i]]==0) c.erase(it);
    } else {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (i=0; i<n; i++) printf("%d%c",r[i]+1,(i==n-1)?'\n':' ');
  return 0;
}