#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,a[1010][1010],r[1010][1010],b[3],v[3],p[3];
char s[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
    scanf("%s",s);
    for (i=0; i<3; i++) {
      b[i]=0; p[i]=i;
    }
    for (i=0; i<m; i++) if (s[i]=='R') ++b[p[1]];
      else if (s[i]=='L') --b[p[1]];
      else if (s[i]=='D') ++b[p[0]];
      else if (s[i]=='U') --b[p[0]];
      else if (s[i]=='I') swap(p[1],p[2]);
      else if (s[i]=='C') swap(p[0],p[2]);
    for (i=0; i<3; i++) b[i]=(b[i]%n+n)%n;
    for (i=0; i<n; i++) for (j=0; j<n; j++) {
      v[0]=(i+b[0])%n;
      v[1]=(j+b[1])%n;
      v[2]=(a[i][j]-1+b[2])%n;
      r[v[p[0]]][v[p[1]]]=v[p[2]]+1;
    }
    for (i=0; i<n; i++,puts("")) for (j=0; j<n; j++) printf("%d ",r[i][j]);
    puts("");
  }
  return 0;
}