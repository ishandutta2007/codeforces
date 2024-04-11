#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MX=200200;
int n,m,i,j,cur,x,y,ay,fi,fr,q[MX],cnt[MX],c[MX],b[MX][2],z[MX][2];
priority_queue <pii, vector<pii>, greater<pii> > all;
bool was[MX],w[MX];
vector<int> a[MX];
char r[MX];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&cnt[i]);
    for (j=0; j<cnt[i]; j++) {
      scanf("%d",&x);
      a[i].push_back(x);
      y=int(x>0);
      x=abs(x);
      b[x][c[x]]=i;
      z[x][c[x]++]=y;
    }
    all.push(make_pair(cnt[i],i));
  }
  for (i=1; i<=m; i++) if (c[i]<2 || z[i][0]==z[i][1]) {
    r[i]=z[i][0]+'0';
    was[i]=true;
    q[fr++]=i;
  }
  while (!all.empty()) {
    while (fi<fr) {
      x=q[fi++];
      for (i=0; i<c[x]; i++) {
        cur=b[x][i];
        if (w[cur]) continue;
        w[cur]=true;
        for (j=0; j<a[cur].size(); j++) {
          y=a[cur][j];
          ay=abs(y);
          if (was[ay]) continue;
          r[ay]=int(y<0)+'0';
          was[ay]=true;
          q[fr++]=ay;
        }
      }
    }
    cur=all.top().second;
    all.pop();
    if (w[cur]) continue;
    for (j=0; j<a[cur].size(); j++) {
      y=a[cur][j];
      ay=abs(y);
      if (was[ay]) continue;
      r[ay]=int(y>0)+'0';
      was[ay]=true;
      w[cur]=true;
      break;
    }
    if (!w[cur]) { puts("NO"); return 0; }
    for (i=0; i<c[ay]; i++) {
      x=b[ay][i];
      if (w[x]) continue;
      all.push(make_pair(--cnt[x],x));
    }
    for (j++; j<a[cur].size(); j++) {
      y=a[cur][j];
      ay=abs(y);
      if (was[ay]) continue;
      r[ay]=int(y<0)+'0';
      was[ay]=true;
      q[fr++]=ay;
    }
  }
  puts("YES");
  puts(r+1);
  return 0;
}