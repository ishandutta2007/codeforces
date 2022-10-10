#include <stdio.h>
int n,m,i,a[30300];
bool f[30300];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<n; i++) scanf("%d",&a[i]);
  f[1]=true;
  for (i=1; i<m; i++) if (f[i]) f[i+a[i]]=true;
  puts(f[m]?"YES":"NO");
  return 0;
}