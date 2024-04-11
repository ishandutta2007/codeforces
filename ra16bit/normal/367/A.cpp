#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,i,j,l,r,mn,mx,a[100100][3];
char s[100100];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) {
    for (j=0; j<3; j++) a[i+1][j]=a[i][j];
    a[i+1][s[i]-'x']++;
  }
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&l,&r);
    if (r-l<2) { puts("YES"); continue; }
    mn=mx=a[r][0]-a[l-1][0];
    for (j=1; j<3; j++) {
      mn=min(mn,a[r][j]-a[l-1][j]);
      mx=max(mx,a[r][j]-a[l-1][j]);
    }
    if (mn+1>=mx) puts("YES"); else puts("NO");
  }
  return 0;
}