#include <bits/stdc++.h>
using namespace std;
int n,s,i,a[1010],b[1010];
int main() {
  scanf("%d%d",&n,&s);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) scanf("%d",&b[i]);
  if (a[1]==0) { puts("NO"); return 0; }
  if (a[s]==1) { puts("YES"); return 0; }
  if (b[s]==0) { puts("NO"); return 0; }
  for (i=s+1; i<=n; i++) if (a[i]==1 && b[i]==1) { puts("YES"); return 0; }
  puts("NO");
  return 0;
}