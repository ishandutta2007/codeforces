#include <bits/stdc++.h>
using namespace std;
int n,i,j,g[1010],r[1010];
string x,y,f[1010];
char s[1010];
int main() {
  scanf("%s",s);
  n=strlen(s);
  f[0]=s[0];
  for (i=1; i<n; i++) {
    x=f[i-1]+s[i];
    y=s[i]+f[i-1];
    //printf("%s vs %s\n",x.c_str(),y.c_str());
    if (y<x) {
      f[i]=move(y); g[i]=1;
    } else f[i]=move(x);
    //printf("%s %d\n",f[i].c_str(),g[i]);
  }
  for (i=n-1, j=0; i>=0; i--) if (g[i]!=j) { r[i]=1; j^=1; }
  for (i=0; i<n; i++) printf("%d ",r[i]);
  return 0;
}