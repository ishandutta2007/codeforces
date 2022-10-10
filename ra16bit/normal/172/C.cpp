#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,t,x,y,i,j,k,r[100100];
vector <pair <int, int> > a;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&t,&x);
    y=max(y,t);
    a.push_back(make_pair(x,i));
    if (i%m==0 || i==n) {
      sort(a.begin(),a.end());
      for (j=0; j<a.size(); j=k) {
        y+=a[j].first-(j==0?0:a[j-1].first);
        for (k=j; k<a.size(); k++) {
          if (a[j].first!=a[k].first) break;
          r[a[k].second]=y;
        }
        y+=(k-j)/2+1;
      }
      y+=a.back().first;
      a.clear();
    }
  }
  for (i=1; i<=n; i++) printf("%d%c",r[i],i==n?'\n':' ');
  return 0;
}