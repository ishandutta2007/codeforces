#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int n,i,x,y,c,cnt,a[100100],b[100100],d[100100],r[100100];
set <pair <int, int> > s,t;
set <pair <int, int> >::iterator it;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    d[a[i]]=i;
  }
  for (i=1; i<=n; i++) {
    scanf("%d",&b[i]);
    c=d[b[i]]-i;
    if (c>=0) s.insert(make_pair(c,b[i])); else t.insert(make_pair(-c,b[i]));
  }
  for (i=n; i>=1; i--) {
    cnt=n-i;
    if (!s.empty()) x=(s.begin()->first)-cnt; else x=n;
    if (!t.empty()) y=(t.begin()->first)+cnt; else y=n;
    r[i%n]=min(x,y);
    while ((!s.empty()) && s.begin()->first==cnt) {
      t.insert(make_pair(-cnt,s.begin()->second));
      s.erase(s.begin());
    }
    it=t.find(make_pair(i-d[b[i]],b[i]));
    if (it!=t.end()) {
      t.erase(it);
      s.insert(make_pair(d[b[i]]+cnt,b[i]));
    }
  }
  for (i=0; i<n; i++) printf("%d\n",r[i]);
  return 0;
}