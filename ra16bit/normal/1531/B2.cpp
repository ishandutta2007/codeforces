#include <bits/stdc++.h>
using namespace std;
int n,i,x,y;
long long r;
map<int,int> cnt;
map<pair<int,int>,int> cp;
pair<int,int> p;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    p={min(x,y),max(x,y)};
    r+=cnt[x];
    if (y!=x) {
      r+=cnt[y];
      r-=cp[p];
    }
    ++cnt[x];
    if (y!=x) {
      ++cnt[y];
      ++cp[p];
    }
  }
  printf("%lld\n",r);
  return 0;
}