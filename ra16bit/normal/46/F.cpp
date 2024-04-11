#include <cstdio>
#include <map>
#include <string>
using namespace std;
int n,m,i,j,k,xx,yy,z,x[1111],y[1111],p[1111],d[1111];
bool a[1111][1111],b[1111][1111],u[1111],v[1111],q=true,e;
char st[18];
string s;
map <string, int> mm;
int findset(int x) {
  if (x!=p[x]) p[x]=findset(p[x]);
  return p[x];
}
int dfindset(int x) {
  if (x!=d[x]) d[x]=dfindset(d[x]);
  return d[x];
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=1; i<=m; i++) scanf("%d%d",&x[i],&y[i]);
  for (i=0; i<k; i++) {
    scanf("%s",st); s=st;
    scanf("%d%d",&xx,&z);
    mm[s]=xx;
    for (j=0; j<z; j++) {
      scanf("%d",&yy);
      a[xx][yy]=true;
    }
  }
  for (i=1; i<=n; i++) p[i]=i;
  while (q) {
    q=false;
    for (i=1; i<=m; i++) if (!u[i]) {
      xx=findset(x[i]);
      yy=findset(y[i]);
      if (xx==yy) continue;
      if (a[xx][i] || a[yy][i]) {
        u[i]=q=true;
        p[yy]=xx;
        for (j=1; j<=m; j++) a[xx][j]|=a[yy][j];
      }
    }
  }
//  for (i=1; i<=n; i++) printf("%d ",findset(i)); puts(""); puts("");
  q=true;
  for (i=0; i<k; i++) {
    scanf("%s",st); s=st;
    scanf("%d%d",&xx,&z);
    if (findset(mm[s])!=findset(xx)) q=false;
    for (j=0; j<z; j++) {
      scanf("%d",&yy);
      b[xx][yy]=true;
    }
  }
  if (!q) { puts("NO"); return 0; }
  for (i=1; i<=n; i++) d[i]=i;
  while (q) {
    q=false;
    for (i=1; i<=m; i++) if (!v[i]) {
      xx=dfindset(x[i]);
      yy=dfindset(y[i]);
      if (xx==yy) continue;
      if (b[xx][i] || b[yy][i]) {
        v[i]=q=true;
        d[yy]=xx;
        for (j=1; j<=m; j++) b[xx][j]|=b[yy][j];
      }
    }
  }
//  for (i=1; i<=n; i++) printf("%d ",dfindset(i)); puts(""); puts("");
  for (i=1; i<=n; i++) { p[i]=findset(i); d[i]=dfindset(i); }
  q=true;
  for (i=1; i<=n; i++) if (q) {
    e=true;
    for (j=1; j<i; j++) if (p[j]==p[i]) { e=false; break; }
    if (!e) continue;
    for (j=1; j<=n; j++) if ((p[i]==p[j])!=(d[i]==d[j])) { q=false; break; }
    if (!q) break;
    for (j=1; j<=m; j++) if (a[p[i]][j]!=b[d[i]][j]) { q=false; break; }
  }
  if (q) puts("YES"); else puts("NO");
  return 0;
}