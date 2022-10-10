#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,r;
char s[55][55],a[5];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=1; i<n; i++) for (j=1; j<m; j++) {
    a[0]=s[i-1][j-1];
    a[1]=s[i][j-1];
    a[2]=s[i-1][j];
    a[3]=s[i][j];
    sort(a,a+4);
    if (a[0]=='a' && a[1]=='c' && a[2]=='e' && a[3]=='f') r++;
  }
  printf("%d\n",r);
  return 0;
}