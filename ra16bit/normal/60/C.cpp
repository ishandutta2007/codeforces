#include <cstdio>
#include <vector>
using namespace std;
int n,m,it,i,j,x,y,z,e,gg,fr,ze,zg,DD,C[111],D[111],r[111],d[111],u[111],w[111],s[111],nod[111][111],nok[111][111],p[2];
vector <int> g[111];
bool a[1000100],q=true;
long long zz;
int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }
void dfs(int x, int c) {
  int j,k;
  s[fr++]=x; w[x]=it; C[x]=c; D[x]=z;
  for (j=0; j<g[x].size(); j++) {
    k=g[x][j];
    D[x]=gcd(D[x],nok[x][k]/nod[x][k]);
    if (u[k]==it && w[k]!=it) dfs(k,1-c);
    if (w[k]==it && c==C[k]) q=false;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) r[i]=1;
  for (i=0; i<m; i++) {
    scanf("%d%d%d%d",&x,&y,&z,&e);
    if (e%z!=0) q=false;
    g[x].push_back(y); nod[x][y]=nod[y][x]=z;
    g[y].push_back(x); nok[x][y]=nok[y][x]=e;
    d[x]=gcd(d[x],e); r[x]=(r[x]/gcd(r[x],z))*z;
    d[y]=gcd(d[y],e); r[y]=(r[y]/gcd(r[y],z))*z;
  }
  if (q) for (i=1; i<=n; i++) if (d[i]%r[i]!=0) { q=false; break; }
  for (i=1; i<=n && q; i++) for (j=1; j<=n && q; j++) if (nok[i][j]!=0) {
    if (gcd(r[i],r[j])!=nod[i][j]) q=false;
  }
  for (i=2; i<=1000000 && q; i++) if (!a[i]) {
    ++it;
    for (zz=i; zz<=1000000; zz*=i);
    z=zz/i;
    for (x=1; x<=n; x++) if (d[x]!=0 && (d[x]/r[x])%i==0) u[x]=it;
    for (x=1; x<=n; x++) if (u[x]==it && w[x]!=it) {
      fr=0; dfs(x,0);
      if (!q) break;
      p[0]=p[1]=true;
      for (y=0; y<fr; y++) {
        DD=D[s[y]]*gcd(z,r[s[y]]);
        for (j=0; j<g[s[y]].size(); j++) {
          e=g[s[y]][j];
          gg=gcd(z,r[e]);
          ze=gcd(z,nok[s[y]][e]);
          zg=gcd(z,nod[s[y]][e]);
          if (ze!=(DD/gcd(DD,gg))*gg || zg!=gcd(DD,gg)) { p[C[s[y]]]=false; break; }
          if (ze!=((D[e]*gg)/gcd(D[e]*gg,gcd(z,r[s[y]])))*gcd(z,r[s[y]]) || zg!=gcd(gcd(z,r[s[y]]),D[e]*gg)) { p[1-C[s[y]]]=false; break; }
        }
      }
      if (p[0]) {
        for (y=0; y<fr; y++) if (C[s[y]]==0) r[s[y]]*=D[s[y]];
      } else if (p[1]) {
        for (y=0; y<fr; y++) if (C[s[y]]==1) r[s[y]]*=D[s[y]];
      } else { q=false; break; }
    }
    
      //for (int i=1; i<=n; i++) printf("%d ",r[i]); puts("r");

    
    for (j=i+i; j<=1000000; j+=i) a[j]=true;
  }
  for (i=1; i<=n && q; i++) for (j=1; j<=n && q; j++) if (nok[i][j]!=0) {
    if (gcd(r[i],r[j])!=nod[i][j]) q=false;
    if ((r[i]/gcd(r[i],r[j]))*r[j]!=nok[i][j]) q=false;
  }
  if (q) {
    puts("YES");
    for (i=1; i<=n; i++) {
      printf("%d",r[i]);
      if (i==n) putchar('\n'); else putchar(' ');
    }
  } else puts("NO");
  return 0;
}