#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int n,m,l,r,i,j,a,p[100100],f[100100];
pair<int,int> b[100100];
multiset<int> q;
set<int> s;
set<int>::iterator it;
int main() {
  scanf("%d%d%d",&n,&m,&l);
  s.insert(0);
  s.insert(n+1);
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    b[i-1]=make_pair(a,i);
  }
  sort(b,b+n);
  for (i=j=0; i<n; i++) {
    for (; j<n && b[i].first-b[j].first>m; j++) s.insert(b[j].second);
    it=s.upper_bound(b[i].second);
    p[(*it)]=max(p[(*it)],b[i].second);
    --it;
    p[b[i].second]=max(p[b[i].second],(*it));
  }
  f[0]=j=0;
  for (i=1; i<=n; i++) {
    if (i-l>=0 && f[i-l]>=0) q.insert(f[i-l]);
    r=max(r,p[i]);
    for (; j<r && j<=i-l; j++) if (f[j]>=0) q.erase(q.find(f[j]));
    f[i]=q.empty()?-1:((*(q.begin()))+1);
  }
  printf("%d\n",f[n]);
  return 0;
}