#include <stdio.h>
int n,m,c,i,a[111];
char s[111];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n); scanf("%s",s);
  for (i=0; i<n; i++) if (s[i]=='1') a[m++]=i;
  c=a[1]-a[0];
  for (i=2; i<m; i++) if (a[i]-a[i-1]!=c) {
    puts("NO"); return 0;
  }
  puts("YES"); return 0;
}