#include <bits/stdc++.h>
using namespace std;
const int MX=400400;
int n,m,cnt,tot,cur,cc,i,j,nj,now,prv,dwn,res,a[MX],all[MX],c[MX],w[MX],lst[MX],sum[MX],stp[MX];
vector<int> g[MX],o[MX],h[MX];
bool u[MX],filled[MX];
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
void fill_hfs(int i) {
  filled[i]=true;
  for (int x: h[i]) if (!filled[x]) fill_hfs(x);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s+m*i);
  for (i=0; i<m; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++, cur++) if (s[cur]=='#') {
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
    for (cur=m*i, j=0; j<m; j++, cur++) if (w[cur]) {
      lst[j]=w[cur];
      if (++sum[j]==a[j]) stp[j]=w[cur];
    }
  }
  //for (cur=i=0; i<n; i++, puts("")) for (j=0; j<m; j++,cur++) printf("%d ",w[cur]);
  for (i=1; i<=cnt; i++) if (!u[i]) dfs(i);
  for (i=tot; i>0; i--) if (c[all[i]]==0) {
    ++cc;
    ofs(all[i]);
  }
  for (i=1; i<=cnt; i++) for (int x: g[i]) if (c[i]!=c[x]) h[c[i]].push_back(c[x]);
  for (j=0; j<m; ) if (stp[j]>0 && !filled[c[stp[j]]]) {
    ++res;
    now=c[stp[j]];
    fill_hfs(now);
    for (nj=j+1; nj<m; nj++) {
      bool ok=false;
      for (i=n-1; i>=0; i--) {
        cur=w[i*m+nj];
        if (cur>0 && c[cur]==now) { ok=true; break; }
      }
      if (!ok) {
        dwn=-1;
        for (i=n-1; i>=0; i--) {
          cur=w[i*m+nj-1];
          if (cur>0 && c[cur]==now) { dwn=i; break; }
        }
        for (i=dwn; i>=0; i--) {
          cur=w[i*m+nj];
          if (cur>0) { now=c[cur]; ok=true; break; }
        }
      }
      if (!ok) {
        for (i=0; i<n; i++) if (w[i*m+nj-1]) {
          now=c[w[i*m+nj-1]];
          if (!filled[now]) fill_hfs(now);
          break;
        }
        break;
      }
      if (!filled[now]) fill_hfs(now);
      if (stp[nj]>0 && !filled[c[stp[nj]]]) {
        now=c[stp[nj]];
        if (!filled[now]) fill_hfs(now);
      }
    }
    j=nj;
  } else j++;
  printf("%d\n",res);
  return 0;
}