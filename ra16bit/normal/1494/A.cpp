#include <bits/stdc++.h>
using namespace std;
const int MX=55;
int t,i,j,n,b[8];
char s[MX];
bool ok[8];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (i=0; i<8; i++) {
      ok[i]=true;
      b[i]=0;
    }
    for (i=0; i<n; i++) for (j=0; j<8; j++) if (ok[j]) {
      if (j&(1<<(s[i]-'A'))) b[j]++; else b[j]--;
      if (b[j]<0) ok[j]=false;
    }
    for (j=0; j<8; j++) if (b[j]==0 && ok[j]) break;
    if (j<8) puts("YES"); else puts("NO");
  }
  return 0;
}