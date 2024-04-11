#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair <int, int> pii;
int n,i,j,y,md,all,last,res,w,cur,nxt,u[5050],k[5050],a[5050][5050];
priority_queue <pii, vector<pii>, greater<pii> > q[2];
vector <pii> s;
long long x;
// old solution
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%I64d%d%d",&k[i],&a[i][1],&x,&y,&md);
    for (j=2; j<=k[i]; j++) a[i][j]=(a[i][j-1]*x+y)%md;
    q[cur].push(make_pair(a[i][1],i));
    u[i]=1;
    all+=k[i];
  }
  if (all>200000) {
    for (i=0; i<n; i++) {
      for (w=0, j=2; j<=k[i]; j++) if (a[i][j]<a[i][j-1]) w++;
      if (w>res) res=w;
    }
    printf("%d\n",res);
    return 0;
  }
  x=y=1;
  for (i=0; i<all; i++) {
    if (q[cur].empty()) cur=1-cur;
    w=q[cur].top().second;
    q[cur].pop();
    y=u[w];
    if (a[w][y]<last) res++;
    last=a[w][y];
    s.push_back(make_pair(a[w][y],w+1));
    if (++u[w]<=k[w]) {
      nxt=a[w][u[w]];
      q[(nxt<last)?(1-cur):cur].push(make_pair(nxt,w));
    }
  }
  printf("%d\n",res);
  for (i=0; i<s.size(); i++) printf("%d %d\n",s[i].first,s[i].second);
  return 0;
}