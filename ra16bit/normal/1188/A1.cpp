#include <bits/stdc++.h>
using namespace std;
int n,i,x,y,v[100100];
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    ++v[x];
    ++v[y];
  }
  for (i=1; i<=n; i++) if (v[i]==2) { puts("NO"); return 0; }
  puts("YES");
  return 0;
}