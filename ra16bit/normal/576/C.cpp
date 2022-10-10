#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,j,k,x,y;
vector<pair<int,int> > v[1010];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    v[x/1000].push_back(make_pair(y,i+1));
  }
  for (i=j=0; i<1010; i++) if (!v[i].empty()) {
    sort(v[i].begin(),v[i].end());
    if (j) reverse(v[i].begin(),v[i].end());
    for (k=0; k<v[i].size(); k++) printf("%d ",v[i][k].second);
    j^=1;
  }
  return 0;
}