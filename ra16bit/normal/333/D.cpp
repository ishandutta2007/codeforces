#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n,m,k,i,j,x,y,z,a[1001][1001];
bool u[1001][1001];
vector<int> v[1001];
pii b[1001*1001];
bool cmp(pii x, pii y) {
  return a[x.first][x.second]>a[y.first][y.second];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&a[i][j]);
    b[k++]=make_pair(i,j);
  }
  sort(b,b+k,cmp);
  for (i=0; i<k; i++) {
    x=b[i].first;
    y=b[i].second;
    for (j=0; j<v[x].size(); j++) {
      z=v[x][j];
      if (u[y][z]) {
        printf("%d\n",a[x][y]);
        return 0;
      }
      u[y][z]=true;
      u[z][y]=true;
    }
    v[x].push_back(y);
  }
  return 0;
}