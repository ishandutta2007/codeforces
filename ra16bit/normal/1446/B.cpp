#include <bits/stdc++.h>
using namespace std;
const int MX=5005;
int n,m,i,j,r,f[MX][MX];
char s[MX],t[MX];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  scanf("%s",t);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    f[i+1][j+1]=max(f[i+1][j+1],f[i][j+1]-1);
    f[i+1][j+1]=max(f[i+1][j+1],f[i+1][j]-1);
    if (s[i]==t[j]) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+2);
    r=max(r,f[i+1][j+1]);
  }
  printf("%d\n",r);
  return 0;
}