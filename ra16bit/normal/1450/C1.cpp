#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,x,a[5];
char s[444][444];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for (i=0; i<n; i++) {
      scanf("%s",s[i]);
      for (j=0; j<n; j++) if (s[i][j]=='X') ++a[(i+j)%3];
    }
    for (x=j=0; j<3; j++) if (a[j]<a[x]) x=j;
    for (i=0; i<n; i++) for (j=0; j<n; j++) if ((i+j)%3==x && s[i][j]=='X') s[i][j]='O';
    for (i=0; i<n; i++) puts(s[i]);
  }
  return 0;
}