#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,t,num,x,y,z,i,j,cur,r[100100];
pair<int,int> last[100100];
vector<int> g[100100];
bool q;
int main() {
  scanf("%d%d%d",&n,&m,&t);
  for (i=0; i<n; i++) {
    scanf("%d:%d:%d",&x,&y,&z);
    g[(x*60+y)*60+z].push_back(i);
  }
  for (i=0; i<86400; i++) {
    if (i-t>=0) for (j=0; j<g[i-t].size(); j++) if (last[r[g[i-t][j]]]==make_pair(i-t,j)) cur--;
    for (j=0; j<g[i].size(); j++) {
      if (cur<m) { cur++; num++; }
      r[g[i][j]]=num;
      last[num]=make_pair(i,j);
    }
    if (cur==m) q=true;
  }
  if (q) {
    printf("%d\n",num);
    for (i=0; i<n; i++) printf("%d\n",r[i]);
  } else puts("No solution");
  return 0;
}