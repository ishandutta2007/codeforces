#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,x,y,c[5],p[5];
char s[5][300300],r[300300];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<3; i++) { scanf("%s",s[i]); p[i]=0; }
    for (i=0; ; i++) {
      for (j=0; j<2; j++) c[j]=0;
      for (j=0; j<3; j++) ++c[s[j][p[j]]-'0'];
      r[i]='0'+int(c[1]>c[0]);
      for (j=0; j<3; j++) if (s[j][p[j]]==r[i]) ++p[j];
      for (j=0; j<3; j++) if (p[j]==2*n) break;
      if (j<3) {
        for (x=0; x<3; x++) if (x!=j) {
          y=3-x-j;
          if (p[y]>p[x]) x=y;
          for (i++; p[x]<2*n; i++, p[x]++) r[i]=s[x][p[x]];
          for (; i<3*n; i++) r[i]='0';
          break;
        }
        break;
      }
    }
    r[3*n]=0;
    puts(r);
  }
  return 0;
}