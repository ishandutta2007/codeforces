#include <stdio.h>
int i,n,m,k,r,j,b[1010];
bool a[1010];
int main() {
  scanf("%d%d",&n,&k);
  for (i=2; i<=n; i++) if (!a[i]) {
    b[m++]=i;
    for (j=i*2; j<=n; j+=i) a[j]=true;
  }
  for (i=0; i<m; i++) {
    for (j=0; j<i; j++) if (b[i]-1-b[j]==b[j+1]) {
      r++; break;
    }
  }
  if (r>=k) puts("YES"); else puts("NO");
  return 0;
}