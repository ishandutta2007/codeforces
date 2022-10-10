#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<long long, pair<long long, long long> > plll;
priority_queue<plll, vector<plll>, greater<plll> > q;
pair<long long,int> a[200200];
int n,i;
long long x,s,k,b,k2,b2,r=1000000000000000000LL;
void check() {
  r=min(r,(s-b+k-1)/k);
}
int main() {
  scanf("%d%I64d",&n,&s);
  for (i=0; i<n; i++) scanf("%d%I64d",&a[i].second,&a[i].first);
  a[n].first=s; a[n++].second=1;
  sort(a,a+n);
  for (i=0; i<n; i++) if (a[i].first==0) {
    if (i==0 || a[i].second>k) k=a[i].second;
  } else {
    check();
    x=(a[i].first-b+k-1)/k;
    //printf("%I64d\n",a[i].first-b+k-1);
    while (!q.empty()) {
      if (q.top().first>x) break;
      k2=q.top().second.first;
      b2=q.top().second.second;
      if (k2*q.top().first+b2>k*q.top().first+b || (k2*q.top().first+b2==k*q.top().first+b && k2>k)) {
        k=k2; b=b2;
        check();
        x=(a[i].first-b+k-1)/k;
      } else if (k2>k) q.push(make_pair((b-b2+k2-k-1)/(k2-k),make_pair(k2,b2)));
      q.pop();
    }
    k2=a[i].second;
    if (k2>k) {
      b2=x*(k-k2)+b-a[i].first;
    //printf("~ %I64d %I64d | %I64d %d %d %d\n",k,b,x,int(k*x-b),int(k2),int(b2));
    //printf("%I64d %I64d\n",b-b2,k2-k);
      q.push(make_pair((b-b2+k2-k-1)/(k2-k),make_pair(k2,b2)));
    //printf("%I64d %I64d %I64d\n",q.top().first,q.top().second.first,q.top().second.second);
    }
    //printf("%d %d at %d: %d %d\n",i,n,int(x),int(k),int(b));
    //check();
    if (x>(s-b)/k) break;
  }
  if (k*x+b<=s) check();
  printf("%I64d\n",r);
  return 0;
}