#include <bits/stdc++.h>
using namespace std;
int n,m,i,q;
char s[22][22],t[22][22];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<m; i++) scanf("%s",t[i]);
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&i);
    --i;
    printf("%s%s\n",s[i%n],t[i%m]);
  }
  return 0;
}