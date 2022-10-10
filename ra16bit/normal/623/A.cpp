#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,y,ca,cc,cur;
vector<int> g[505];
char s[505];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
  }
  for (i=0; i<n; i++) if (g[i].size()==n-1) s[i]='b';
  for (i=0; i<n; i++) if (s[i]!='b') {
    s[i]='a';
    ca=g[i].size();
    for (j=0; j<g[i].size(); j++) if (s[g[i][j]]!='b') s[g[i][j]]='a';
    break;
  }
  for (j=0; j<n; j++) if (s[j]==0) {
    s[j]='c';
    cc++;
  }
  for (i=0; i<n; i++) if (s[i]!='b') {
    for (cur=j=0; j<g[i].size(); j++) if (s[g[i][j]]!='b') {
      if (s[g[i][j]]!=s[i]) break;
      cur++;
    }
    if (j<g[i].size()) { puts("No"); return 0; }
    if (s[i]=='a' && g[i].size()!=ca) { puts("No"); return 0; }
    if (s[i]=='c' && cur!=cc-1) { puts("No"); return 0; }
  }
  puts("Yes");
  puts(s);
  return 0;
}