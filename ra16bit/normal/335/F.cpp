#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,i,j,k,cur,diff,now,a[500500];
long long r;
vector<int> v;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
  scanf("%d",&n);
  v.reserve(n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  reverse(a,a+n);
  for (i=0; i<n; i=j) {
    for (j=i; j<n && a[i]==a[j]; j++) r+=a[j];
    now=min(i-2*int(q.size()),j-i);
    diff=min(i,j-i)-now;
    v.clear();
    for (k=0; k<now; k++) v.push_back(a[i]);
    for (k=0; k<diff && !q.empty(); k+=2) {
      cur=q.top(); q.pop();
      if (cur<a[i]) {
        v.push_back(a[i]);
        if (k+1<diff) v.push_back(a[i]);
      } else {
        v.push_back(cur);
        if (k+1<diff) v.push_back(max(0,2*a[i]-cur));
      }
    }
    for (k=0; k<v.size(); k++) q.push(v[k]);
  }
  while (!q.empty()) {
    r-=q.top();
    q.pop();
  }
  printf("%I64d\n",r);
  return 0;
}