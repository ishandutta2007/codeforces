#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n,m,i,j,k[4];
bool a[4],g[277];
string s[4];
int main() {
  g['a']=true; g['e']=true; g['i']=true; g['o']=true; g['u']=true;
  cin>>n>>m;
  for (i=0; i<n; i++) {
    for (j=0; j<4; j++) {
      cin>>s[j];
      int p=0;
      for (k[j]=s[j].length()-1; k[j]>=0; k[j]--) {
        if (g[s[j][k[j]]]) p++;
        if (p==m) break;
      }
      if (k[j]<0) { puts("NO"); return 0; }
    }
    if (s[0].substr(k[0])!=s[1].substr(k[1]) || s[2].substr(k[2])!=s[3].substr(k[3])) a[0]=true;
    if (s[0].substr(k[0])!=s[2].substr(k[2]) || s[1].substr(k[1])!=s[3].substr(k[3])) a[1]=true;
    if (s[0].substr(k[0])!=s[3].substr(k[3]) || s[2].substr(k[2])!=s[1].substr(k[1])) a[2]=true;
    if (s[0].substr(k[0])!=s[1].substr(k[1]) || s[0].substr(k[0])!=s[2].substr(k[2]) || s[0].substr(k[0])!=s[3].substr(k[3])) a[3]=true;
  }
  if (!a[3]) puts("aaaa"); else if (!a[0]) puts("aabb"); else if (!a[1]) puts("abab"); else if (!a[2]) puts("abba"); else puts("NO");
  return 0;
}