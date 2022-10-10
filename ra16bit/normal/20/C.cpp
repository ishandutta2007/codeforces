#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int i,x,y,z,n,m,num,h[111111],o[111111],v[111111];
long long p[111111],zz;
vector <int> f[111111],g[111111],r;
void hUp(int i) {
  while (i>1 && p[h[i/2]]>p[h[i]]) {
    swap(h[i],h[i/2]);
    o[h[i]]=i; i/=2; o[h[i]]=i;
  }
}
int exMin() {
  swap(h[1],h[num]); o[h[1]]=1;
  int i=1,k; num--;
  while (2*i<=num) {
    if (p[h[2*i]]<p[h[i]]) k=2*i; else k=i;
    if (2*i<num) if (p[h[2*i+1]]<p[h[k]]) k=2*i+1;
    if (i==k) break;
    swap(h[i],h[k]);
    o[h[i]]=i; i=k; o[h[i]]=i;
  }
  return h[num+1];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); f[x].push_back(z);
    g[y].push_back(x); f[y].push_back(z);
  }
  for (i=2; i<=n; i++) p[i]=-1;
  o[1]=h[1]=num=1;
  while (num>0) {
    x=exMin();
    for (i=0; i<g[x].size(); i++) {
      y=g[x][i]; zz=p[x]+f[x][i];
      if (p[y]==-1) {
        p[y]=zz; v[y]=x; o[y]=++num; h[num]=y; hUp(o[y]);
      } else if (zz<p[y]) {
        p[y]=zz; v[y]=x; hUp(o[y]);
      }
    }
  }
  if (p[n]==-1) puts("-1"); else {
    for (i=n; i>=1; i=v[i]) r.push_back(i);
    for (i=r.size()-1; i>=0; i--) {
      printf("%d",r[i]);
      if (i) putchar(' '); else putchar('\n');
    }
  }
  return 0;
}