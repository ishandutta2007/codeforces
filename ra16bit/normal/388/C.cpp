#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,x,a[2];
vector<int> v;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&m);
    for (j=0; j<m; j++) {
      scanf("%d",&x);
      if (m%2==1 && j*2+1==m) {
        v.push_back(x);
      } else a[int(j*2>=m)]+=x;
    }
  }
  sort(v.rbegin(),v.rend());
  for (i=0; i<v.size(); i++) a[i%2]+=v[i];
  printf("%d %d\n",a[0],a[1]);
  return 0;
}