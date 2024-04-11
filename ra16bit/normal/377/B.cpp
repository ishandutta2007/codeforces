#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n,m,s,i,j,l,r,h,c[100100],res[100100];
pii a[100100],b[100100];
bool solve(int h) {
  int i,j;
  long long cur;
  priority_queue<pii,vector<pii>,greater<pii> > q;
  for (i=j=cur=0; i<m; i+=h) {
    for (; j<n && b[j].first>=a[i].first; j++) q.push(make_pair(c[b[j].second],b[j].second));
    if (q.empty()) return false;
    cur+=q.top().first;
    if (cur>s) return false;
    for (int k=0; k<h && i+k<m; k++) res[a[i+k].second]=q.top().second;
    q.pop();
  }
  return true;
}
int main() {
  scanf("%d%d%d",&n,&m,&s);
  for (i=0; i<m; i++) { scanf("%d",&a[i].first); a[i].second=i; }
  for (i=0; i<n; i++) { scanf("%d",&b[i].first); b[i].second=i; }
  for (i=0; i<n; i++) scanf("%d",&c[i]);
  sort(a,a+m); reverse(a,a+m);
  sort(b,b+n); reverse(b,b+n);
  if (!solve(m)) { puts("NO"); return 0; }
  l=1; r=m;
  while (l<r) {
    h=(l+r)/2;
    if (solve(h)) r=h; else l=h+1;
  }
  puts("YES");
  solve(r);
  for (i=0; i<m; i++) printf("%d%c",res[i]+1,(i==m-1)?'\n':' ');
  return 0;
}