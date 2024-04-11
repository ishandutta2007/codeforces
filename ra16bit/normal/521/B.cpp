#include <cstdio>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
const int md=1000000009;
int n,i,z,x[100100],y[100100];
long long r;
map<pii,int> m;
set<int> s;
set<int>::iterator it;
int down(int x, int y) {
  if (m.count(make_pair(x,y))==0) return 5;
  return m.count(make_pair(x-1,y-1))+m.count(make_pair(x,y-1))+m.count(make_pair(x+1,y-1));
}
bool ok(int x, int y) {
  return (down(x-1,y+1)>1 && down(x,y+1)>1 && down(x+1,y+1)>1);
}
void check(int x, int y) {
  pii p=make_pair(x,y);
  if (m.count(p)==0) return;
  int i=m[p];
  if (s.count(i)) return;
  if (ok(x,y)) s.insert(i);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    m[make_pair(x[i],y[i])]=i;
  }
  for (i=0; i<n; i++) check(x[i],y[i]);
  for (z=1; !s.empty(); z^=1) {
    while (true) {
      if (z) {
        it=s.end();
        it--;
      } else it=s.begin();
      i=(*it);
      s.erase(it);
      if (ok(x[i],y[i])) break;
    }
    m.erase(make_pair(x[i],y[i]));
    check(x[i]-1,y[i]-1);
    check(x[i],y[i]-1);
    check(x[i]+1,y[i]-1);
    r=(r*n+i)%md;
  }
  printf("%d\n",int(r));
  return 0;
}