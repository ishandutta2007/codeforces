#include <set>
#include <vector>
#include <cstdio>
using namespace std;
struct Node {
  long long p,q; int i;
  Node() { p=q=i=0; }
  Node(long long pp, long long qq, int ii) : p(pp),q(qq),i(ii) {}
} best,cur;
bool operator < (const Node& x, const Node& y) {
  if (x.p*y.q!=y.p*x.q) return x.p*y.q<y.p*x.q;
  return x.i<y.i;
}
int n,m,k,i,j,x,y,c[100100];
vector<int> g[100100],r;
bool b[100100],was;
set<Node> s;
int main() {
  scanf("%d%d%d",&n,&m,&k);
  while (k--) {
    scanf("%d",&x);
    b[x]=true;
  }
  while (m--) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (!b[i]) {
    for (j=0; j<g[i].size(); j++)
      if (!b[g[i][j]]) c[i]++;
    s.insert(Node(c[i],g[i].size(),i));
  }
  while (!s.empty()) {
    cur=*s.begin();
    if (best.i==0 || best<cur) best=cur;
    b[cur.i]=true;
    r.push_back(cur.i);
    s.erase(s.begin());
    for (j=0; j<g[cur.i].size(); j++) {
      x=g[cur.i][j];
      if (!b[x]) {
        s.erase(s.find(Node(c[x],g[x].size(),x)));
        c[x]--;
        s.insert(Node(c[x],g[x].size(),x));
      }
    }
  }
  for (i=0; i<r.size(); i++) if (was || r[i]==best.i) {
    if (was) putchar(' '); else printf("%d\n",int(r.size())-i);
    printf("%d",r[i]);
    was=true;
  }
  puts("");
  return 0;
}