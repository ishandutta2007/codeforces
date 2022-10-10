#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,x,y,z,i,j,k,a[100100][33],c[33],l[33],r[100100];
vector<pair<int,int> > b[100100];
int main() {
  scanf("%d%d",&n,&m);
  while (m--) {
    scanf("%d%d%d",&x,&y,&z);
    for (i=0; i<30; i++) if ((z>>i)&1) a[x][i]++;
    b[y].push_back(make_pair(x,z));
  }
  for (i=1; i<=n; i++) {
    for (j=0; j<30; j++) {
      c[j]+=a[i][j];
      if (c[j]>0) r[i]+=(1<<j); else l[j]=i;
    }
    for (k=0; k<b[i].size(); k++) {
      for (j=0; j<30; j++) if ((b[i][k].second>>j)&1) {
        if (l[j]>=b[i][k].first) { puts("NO"); return 0; }
        c[j]--;
      } else if (l[j]<b[i][k].first) { puts("NO"); return 0; }
    }
  }
  puts("YES");
  for (i=1; i<=n; i++) printf("%d%c",r[i],i==n?'\n':' ');
  return 0;
}