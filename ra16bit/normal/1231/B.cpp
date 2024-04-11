#include <bits/stdc++.h>
using namespace std;
int n,m,i;
char s[200200];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  if (n==1) {
    if (s[0]!='0' && m>0) s[0]='0';
  } else {
    if (s[0]!='1' && m>0) { s[0]='1'; m--; }
    for (i=1; i<n && m>0; i++) if (s[i]!='0') {
      s[i]='0'; m--;
    }
  }
  puts(s);
  return 0;
}