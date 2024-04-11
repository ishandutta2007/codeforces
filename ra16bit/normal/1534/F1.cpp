#include <bits/stdc++.h>
using namespace std;
const int MX=400400;
int n,m,cnt,tot,cur,cc,i,j,a[MX],all[MX],c[MX],w[MX],lst[MX];
vector<int> g[MX],o[MX];
bool u[MX],b[MX];
char s[MX];
void dfs(int i) {
  u[i]=true;
  for (int x: g[i]) if (!u[x]) dfs(x);
  all[++tot]=i;
}
void ofs(int i) {
  c[i]=cc;
  for (int x: o[i]) if (c[x]==0) ofs(x);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s+m*i);
  for (i=0; i<m; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++, cur++) if (s[cur]=='#') {
    w[cur]=++cnt;
    if (i>0 && s[cur-m]=='#') {
      g[cnt].push_back(w[cur-m]);
      o[w[cur-m]].push_back(cnt);
    }
    if (j>0 && s[cur-1]=='#') {
      g[cnt].push_back(w[cur-1]);
      g[w[cur-1]].push_back(cnt);
      o[cnt].push_back(w[cur-1]);
      o[w[cur-1]].push_back(cnt);
    }
  }
  for (i=n-1; i>=0; i--) {
    for (cur=m*i, j=0; j<m; j++, cur++) if (w[cur]) {
      if (lst[j]) {
        g[w[cur]].push_back(lst[j]);
        o[lst[j]].push_back(w[cur]);
      }
      if (j>0 && lst[j-1]) {
        g[w[cur]].push_back(lst[j-1]);
        o[lst[j-1]].push_back(w[cur]);
      }
      if (j+1<m && lst[j+1]) {
        g[w[cur]].push_back(lst[j+1]);
        o[lst[j+1]].push_back(w[cur]);
      }
    }
    for (cur=m*i, j=0; j<m; j++, cur++) if (w[cur]) lst[j]=w[cur];
  }
  //for (cur=i=0; i<n; i++, puts("")) for (j=0; j<m; j++,cur++) printf("%d ",w[cur]);
  for (i=1; i<=cnt; i++) if (!u[i]) dfs(i);
  for (i=tot; i>0; i--) if (c[all[i]]==0) {
    ++cc;
    ofs(all[i]);
  }
  for (i=1; i<=cnt; i++) for (int x: g[i]) if (c[i]!=c[x] && !b[c[x]]) {
    --cc;
    b[c[x]]=true;
  }
  printf("%d\n",cc);
  return 0;
}