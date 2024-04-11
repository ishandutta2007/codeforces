#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=4010,MZ=8*MX;
int n,m,num,cur,i,j,k,t,x,y,z,it,p,kk[MX],b[MX],d[MX],prev[MX],prex[MX],l[MX],r[MX],c[MZ],f[MZ],s[MZ],u[MX];
vector <int> g[MX],v[MX],q,nq;
bool cmp(int i, int j) { return l[i]<l[j]; }
void edge(int i, int j, int k) {
  g[i].push_back(j);
  v[i].push_back(num);
  c[num]=(j==i+n)?1:1000000000; s[num++]=k;
  g[j].push_back(i);
  v[j].push_back(num);
  c[num]=0; s[num++]=-k;
}
int main() {
  scanf("%d%d",&n,&m);
  t=2*n+1;
  for (i=1; i<=n; i++) {
    scanf("%d%d%d",&l[i],&r[i],&cur);
    r[i]=l[i]+r[i]-1;
    edge(0,i,0);
    edge(i,i+n,cur);
    edge(i+n,t,0);
    kk[i]=i;
  }
  sort(kk+1,kk+n+1,cmp);
  for (i=1; i<=n; i++) {
    for (j=1; j<=n; j++) if (l[kk[j]]>r[kk[i]]) { edge(kk[i]+n,kk[j],0); break; }
    if (i<n) edge(kk[i],kk[i+1],0);
  }
  for (k=0; k<m; k++) {
    for (i=1; i<=t; i++) d[i]=-2000000000;
    q.push_back(0);
    for (i=0; i<=t; i++) {
      nq.clear(); ++it;
      for (j=0; j<q.size(); j++) {
        x=q[j];
        for (p=0; p<g[x].size(); p++) {
          y=g[x][p];
          z=v[x][p];
          if (f[z]<c[z] && d[y]<d[x]+s[z]) {
            d[y]=d[x]+s[z];
            prex[y]=x;
            prev[y]=z;
            if (u[y]!=it) {
              u[y]=it;
              nq.push_back(y);
            }
          }
        }
      }
      q=nq;
    }
    if (d[t]<=0) break;
    for (i=t; i!=0; i=prex[i]) {
      f[prev[i]]++;
      f[prev[i]^1]--;
    }
  }
  for (i=1; i<=n; i++) for (j=0; j<g[i].size(); j++) if (g[i][j]==i+n) b[i]=f[v[i][j]];
  for (i=1; i<=n; i++) printf("%d%c",b[i],i==n?'\n':' ');
  return 0;
}