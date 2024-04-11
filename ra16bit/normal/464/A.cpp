#include <stdio.h>
int n,m,i,k;
char c,j,l,s[1010],t[1010];
int main() {
  scanf("%d%d",&n,&m);
  c='a'+m;
  scanf("%s",s);
  for (i=0; i<n; i++) t[i]=s[i];
  for (i=n-1; i>=0; i--) for (j=s[i]+1; j<c; j++) {
    if (i>0 && j==t[i-1]) continue;
    if (i>1 && j==t[i-2]) continue;
    t[i]=j;
    for (k=i+1; k<n; k++) {
      for (l='a'; l<c; l++) if (l!=t[k-1] && (l<2 || l!=t[k-2])) {
        t[k]=l;
        break;
      }
      if (l>=c) break;
    }
    if (k>=n) {
      puts(t);
      return 0;
    }
  }
  puts("NO");
  return 0;
}