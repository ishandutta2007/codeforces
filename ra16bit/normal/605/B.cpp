#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n,m,x,y,i,j,k,cnt,v;
vector<pii> a[2];
pii r[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    a[y].push_back(make_pair(x,i));
  }
  for (i=0; i<2; i++) sort(a[i].begin(),a[i].end());
  cnt=a[0].size();
  for (i=j=0; i<a[1].size(); i++) {
    v=a[1][i].first;
    r[a[1][i].second]=make_pair(i+1,i+2);
    for (k=1; k<=i && j<cnt; k++, j++) {
      if (a[0][j].first<v) { puts("-1"); return 0; }
      r[a[0][j].second]=make_pair(k,i+2);
    }
  }
  if (j<cnt) { puts("-1"); return 0; }
  for (i=0; i<m; i++) printf("%d %d\n",r[i].first,r[i].second);
  return 0;
}