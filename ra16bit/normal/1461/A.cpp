#include <bits/stdc++.h>
using namespace std;
int t,n,m,i;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) putchar('a'+i%3);
    putchar('\n');
  }
  return 0;
}