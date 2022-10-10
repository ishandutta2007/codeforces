#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,m1,m2,tot,a[111];
vector<int> g[111];
bool u[111],w[111];
char s[111][111];
bool q=true;
void dfs(int i) {
  u[i]=true;
  w[i]=true;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (!u[k]) dfs(k); else if (w[k]) q=false;
  }
  w[i]=false;
  a[++tot]=i;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=1; i<n; i++) {
    m1=strlen(s[i-1]);
    m2=strlen(s[i]);
    for (j=0; j<m1 && j<m2 && s[i-1][j]==s[i][j]; j++);
    if (j<m1 && j<m2) g[s[i-1][j]-'a'].push_back(s[i][j]-'a'); else if (m1>m2) q=false;
  }
  for (i=0; i<26; i++) if (!u[i]) dfs(i);
  if (q) {
    for (i=tot; i>0; i--) putchar(a[i]+'a');
  } else puts("Impossible");
  return 0;
}