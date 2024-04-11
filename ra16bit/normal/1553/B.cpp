#include <bits/stdc++.h>
using namespace std;
const int MX=1010;
int t,it,n,m,i,j,a[MX][MX],b[MX][MX];
char s[MX],z[MX];
bool ok;
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%s",s); n=strlen(s);
    scanf("%s",z); m=strlen(z);
    for (i=0; i<n; i++) {
      for (j=0; j<m && i+j<n; j++) {
        if (s[i+j]!=z[j]) break;
        a[i+j][j]=it;
      }
      for (j=0; j<m && i+j<n; j++) {
        if (s[i+j]!=z[m-1-j]) break;
        b[i+j][m-1-j]=it;
      }
    }
    ok=false;
    for (i=0; i<n && !ok; i++) for (j=0; j<m && !ok; j++) if (a[i][j]==it && b[i][j]==it) ok=true;
    puts(ok?"YES":"NO");
  }
  return 0;
}