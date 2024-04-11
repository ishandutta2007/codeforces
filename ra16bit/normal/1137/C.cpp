#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,d,cc,cur,i,j,x,y,z,tot,fi,fr,all[MX],qx[MX*52],qy[MX*52],dst[MX],dd[MX],c[MX],f[MX][52];
vector<int> g[MX],o[MX],v[MX];
bool u[MX],ww[MX],w[MX][52];
char s[MX][52];
void dfs(int i) {
  u[i]=true;
  for (int j=0; j<g[i].size(); j++) if (!u[g[i][j]]) dfs(g[i][j]);
  all[++tot]=i;
}
void ofs(int i, int ds) {
  v[cc].push_back(i);
  //printf("%d : %d (%d)\n",i,cc,ds);
  c[i]=cc;
  dst[i]=ds;
  for (int j=0; j<o[i].size(); j++) if (c[o[i][j]]==0) ofs(o[i][j],ds+1);
}
void solve(int cur) {
  ww[cur]=true;
  for (int xx=0; xx<v[cur].size(); xx++) {
    int x=v[cur][xx];
    for (int jj=0; jj<g[x].size(); jj++) {
      int y=g[x][jj];
      if (c[y]!=cur) {
        if (!ww[c[y]]) solve(c[y]);
        for (int j=0; j<dd[cur]; j++) {
          int ja=(j+dst[x])%dd[cur];
          for (int k=j; k<d; k+=dd[cur]) f[cur][ja]=max(f[cur][ja],f[c[y]][(k+1+dst[y])%dd[c[y]]]);
        }
      }
    }
  }
  for (int xx=0; xx<v[cur].size(); xx++) {
    int x=v[cur][xx];
    for (int j=0; j<dd[cur]; j++) {
      int ja=(j+dst[x])%dd[cur];
      for (int k=j; k<d; k+=dd[cur]) if (s[x][k]=='1') {
        f[cur][ja]++;
        break;
      }
    }
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&d);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    o[y].push_back(x);
  }
  for (i=1; i<=n; i++) {
    scanf("%s",s[i]);
    if (!u[i]) dfs(i);
  }
  for (i=tot; i>0; i--) if (c[all[i]]==0) {
    ++cc;
    ofs(all[i],0);
    qx[0]=all[i];
    qy[0]=0;
    w[all[i]][0]=true;
    //printf("%d: \n",cc);
    for (fi=0, fr=1; fi<fr; fi++) {
      //printf("q %d %d\n",qx[fi],qy[fi]);
      x=qx[fi];
      z=(qy[fi]+1)%d;
      for (j=0; j<g[x].size(); j++) {
        y=g[x][j];
        if (c[y]==cc && !w[y][z]) {
          qx[fr]=y;
          qy[fr++]=z;
          w[y][z]=true;
        }
      }
    }
    for (dd[cc]=1; dd[cc]<d; dd[cc]++) if (w[all[i]][dd[cc]]) break;
  }
  for (cur=cc; cur>0; cur--) if (!ww[cur]) solve(cur);
  printf("%d\n",f[c[1]][dst[1]%dd[c[1]]]);
  return 0;
}