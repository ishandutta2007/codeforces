#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,m,i,j,cur;
char s[MX],z[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s); n=strlen(s);
    scanf("%s",z); m=strlen(z);
    cur=((n&1)^(m&1));
    for (i=j=0; i<n; i++) if ((i&1)==cur && j<m && s[i]==z[j]) {
      cur^=1;
      ++j;
    }
    puts((j==m)?"YES":"NO");
  }
  return 0;
}