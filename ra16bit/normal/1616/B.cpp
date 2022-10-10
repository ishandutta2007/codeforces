#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,j;
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    if (n==1 || s[0]<=s[1]) {
      putchar(s[0]);
      putchar(s[0]);
      putchar('\n');
      continue;
    }
    for (i=1; i<n; i++) if (s[i]>s[i-1]) break;
    for (j=0; j<i; j++) putchar(s[j]);
    for (j=i-1; j>=0; j--) putchar(s[j]);
    putchar('\n');
  }
  return 0;
}