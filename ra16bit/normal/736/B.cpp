#include <stdio.h>
const int ans[7]={1,1,1,1,2,1,2};
int n,i;
bool q;
int main() {
  scanf("%d",&n);
  for (i=2; i*i<=n; i++) if (n%i==0) { q=true; break; }
  if (!q) puts("1"); else if (n>=7) {
    if (n%2) {
      n-=2; q=false;
      for (i=2; i*i<=n; i++) if (n%i==0) { q=true; break; }
      puts(q?"3":"2");
    } else puts("2");
  } else printf("%d\n",ans[n]);
  return 0;
}