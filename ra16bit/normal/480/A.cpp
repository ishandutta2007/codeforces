#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,x,y;
pair<int,int> a[5050];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  for (x=i=0; i<n; i=j) {
    y=x;
    for (j=i; a[i].first==a[j].first; j++)
      y=max(y,(a[j].second>=x)?a[j].second:a[j].first);
    x=y;
  }
  printf("%d\n",x);
  return 0;
}