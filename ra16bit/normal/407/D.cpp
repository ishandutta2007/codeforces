#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,k,x,cur,r,a[402][402],u[402],w[402],d[402];
pair<int,int> p;
vector<pair<int,int> > v[160061];
void upd(int x, int y) {
  if (w[x]!=j) {
    w[x]=j; d[x]=0;
  }
  d[x]=max(d[x],y);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    for (j=0; j<=160000; j++) v[j].clear();
    for (j=0; j<m; j++) { u[j]=0; w[j]=-1; }
    for (j=0; j<m; j++) {
      scanf("%d",&a[i][j]);
      for (x=i; x>=0; x--) {
        k=a[x][j];
        if (v[k].size()>1 && v[k].back().second==j && v[k][v[k].size()-2].second==j) continue;
        while (!v[k].empty() && v[k].back().first<x) {
          upd(v[k].back().second,v[k].back().first+1);
          v[k].pop_back();
        }
        if (!v[k].empty()) upd(v[k].back().second,x+1);
        v[k].push_back(make_pair(x,j));
      }
      cur=0;
      for (x=j; x>=0; x--) {
        if (w[x]==j) cur=max(cur,d[x]);
        u[x]=max(u[x],cur);
        r=max(r,(i-u[x]+1)*(j-x+1));
      }
    }
  }
  printf("%d\n",r);
  return 0;
}