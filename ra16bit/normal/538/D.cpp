#include <stdio.h>
int n,i,j,x,y;
char s[111][111],r[111][111];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<2*n-1; i++) for (j=0; j<2*n-1; j++) r[i][j]='x';
  r[n-1][n-1]='o';
  for (i=0; i<n; i++) for (j=0; j<n; j++) if (s[i][j]=='o')
    for (x=0; x<n; x++) for (y=0; y<n; y++) if (s[x][y]=='.')
      r[n-1+x-i][n-1+y-j]='.';
  for (x=0; x<n; x++) for (y=0; y<n; y++) if (s[x][y]=='x') {
    bool ok=false;
    for (i=0; i<n; i++) for (j=0; j<n; j++) ok|=(s[i][j]=='o' && r[n-1+x-i][n-1+y-j]=='x');
    if (!ok) { puts("NO"); return 0; }
  }
  puts("YES");
  for (i=0; i<2*n-1; i++) puts(r[i]);
  return 0;
}