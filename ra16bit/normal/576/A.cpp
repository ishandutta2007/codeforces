#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,x;
vector<int> r;
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) {
    x=i;
    for (j=2; j<=n; j++) if (i%j==0) {
      while (x%j==0) x/=j;
      break;
    }
    if (x==1) r.push_back(i);
  }
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d ",r[i]);
  return 0;
}