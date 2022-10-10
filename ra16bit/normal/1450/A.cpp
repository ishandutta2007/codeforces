#include <bits/stdc++.h>
using namespace std;
int t,n,i;
char s[222];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    for (i=0; i<n; i++) if (s[i]!='t') putchar(s[i]);
    for (i=0; i<n; i++) if (s[i]=='t') putchar(s[i]);
    putchar('\n');
  }
  return 0;
}