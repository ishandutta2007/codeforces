#include <stdio.h>
int n,m,i,j;
char s[100100];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  for (j=0; j<n-1 && i<m; j++) if (s[j]=='4' && s[j+1]=='7') {
    if (j&1) {
      i++; s[j]='7';
      if (j>0 && s[j-1]=='4') {
        if ((i&1)!=(m&1)) s[j]='4';
        break;
      }
    } else {
      i++; s[j+1]='4';
      if (j+2<n && s[j+2]=='7') {
        if ((i&1)!=(m&1)) s[j+1]='7';
        break;
      }
    }
  }
  puts(s);
  return 0;
}