#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int n,i,x,z[5];
map <int, int> m;
map <int, int>::iterator it;
set <pair <int, int> > s;
pair <int, int> a,b,c;
vector <int> ra,rb,rc;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&x); m[x]++; }
  for (it=m.begin(); it!=m.end(); it++) if (it->second>0) s.insert(make_pair(-it->second,it->first));
  while (!s.empty()) {
    a=*s.begin(); s.erase(s.begin());
    if (s.empty()) break;
    b=*s.begin(); s.erase(s.begin());
    if (s.empty()) break;
    c=*s.begin(); s.erase(s.begin());
    ra.push_back(a.second);
    rb.push_back(b.second);
    rc.push_back(c.second);
    if (++a.first<0) s.insert(a);
    if (++b.first<0) s.insert(b);
    if (++c.first<0) s.insert(c);
  }
  printf("%d\n",int(ra.size()));
  for (i=0; i<ra.size(); i++) {
    z[0]=ra[i]; z[1]=rb[i]; z[2]=rc[i];
    sort(z,z+3);
    printf("%d %d %d\n",z[2],z[1],z[0]);
  }
  return 0;
}