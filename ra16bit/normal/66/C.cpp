#include <iostream>
#include <string>
#include <vector>
using namespace std;
int i,j,k,p,n,m,b[10010],c[10010];
vector <int> g[10010];
vector <string> f[10010];
string s,t;
void dfs(int i, int d) {
  b[i]=g[i].size();
  for (int j=0; j<g[i].size(); j++) {
    dfs(g[i][j],d+1);
    b[i]+=b[g[i][j]];
    c[i]+=c[g[i][j]];
  }
  if (d>1) {
    if (b[i]>k) k=b[i];
    if (c[i]>p) p=c[i];
  }
}
int main() {
  while (cin>>s) {
    n=s.length(); j=0;
    for (i=0; i<n; i=k+1) {
      for (k=i; k<n; k++) if (s[k]=='\\') break;
      if (k<n) {
        t=s.substr(i,k-i);
        for (p=0; p<f[j].size(); p++) if (f[j][p]==t) break;
        if (p==f[j].size()) {
          g[j].push_back(++m);
          f[j].push_back(t);
          j=m;
        } else j=g[j][p];
      } else c[j]++;
    }
  }
  k=p=0; dfs(0,0);
  cout<<k<<' '<<p<<'\n';
  return 0;
}