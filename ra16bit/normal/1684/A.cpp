#include <bits/stdc++.h>
using namespace std;
const int MX=111;
int t,n,i,j;
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    if (n==2) {
      printf("%c\n",s[1]);
      continue;
    }
    for (j=i=0; i<n; i++) if (s[j]>s[i]) j=i;
    printf("%c\n",s[j]);
  }
  return 0;
}