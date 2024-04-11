#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,q,T,i,j,ii,jj,ni,nj,x,xt[MX],d[MX],/*rd[MX],*/p[MX][18],t[2][MX],o[2][MX];
vector<int> g[2][MX];
bool u[2][MX];
void dfs(int x, int i) {
  t[x][i]=++T;
  u[x][i]=true;
  for (int j=0; j<g[x][i].size(); j++) dfs(x,g[x][i][j]);
  o[x][i]=T;
}
void both(int i, int pr, int dep) {//, int rdep) {
  p[i][0]=pr; d[i]=dep;// rd[i]=rdep;
  for (int j=1; j<18; j++) p[i][j]=p[p[i][j-1]][j-1];
  for (int e=0; e<2; e++) for (int j=0; j<g[e][i].size(); j++) both(g[e][i][j],i,dep+1);//,rdep+e);
}
int jmp(int x, int z) {
  for (int i=17; i>=0; i--) if (z>=(1<<i)) {
    x=p[x][i];
    z-=(1<<i);
  }
  return x;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&j,&xt[i]);
    if (xt[i]>=0) g[xt[i]][j].push_back(i);
  }
  for (x=0; x<2; x++) for (T=0, i=1; i<=n; i++) if (xt[i]!=x) dfs(x,i);
  for (i=1; i<=n; i++) if (xt[i]==-1) both(i,0,1);//,1);
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d%d",&x,&i,&j);
    if (x==1) {
      puts((t[0][j]>t[0][i] && t[0][j]<=o[0][i])?"YES":"NO");
    } else {
      ii=i; jj=j;
      if (d[ii]<d[jj]) jj=jmp(jj,d[jj]-d[ii]); else if (d[jj]<d[ii]) ii=jmp(ii,d[ii]-d[jj]);
      for (x=17; x>=0 && ii!=jj; x--) if (p[ii][x]!=p[jj][x]) {
        ii=p[ii][x];
        jj=p[jj][x];
      }
      if (ii!=jj) {
        ii=p[ii][0];
        jj=p[jj][0];
      }
      if (ii==0 || jj==0 || ii!=jj) puts("NO"); else {
        puts((t[0][i]>=t[0][ii] && t[0][i]<=o[0][ii]/* && rd[i]==rd[ii] && rd[j]>rd[ii]*/ && t[1][j]>t[1][ii] && t[1][j]<=o[1][ii])?"YES":"NO");
      }
    }
  }
  return 0;
}