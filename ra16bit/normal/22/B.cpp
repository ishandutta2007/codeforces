#include <stdio.h>
int i,j,ii,jj,x,y,r,n,m;
char s[30][30];
bool q;
int main() {
  scanf("%d%d",&n,&m); gets(s[0]);
  for (i=0; i<n; i++) gets(s[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) for (x=i; x<n; x++) for (y=j; y<m; y++) if ((x-i+y-j+2)*2>r) {
    q=true;
    for (ii=i; ii<=x; ii++) if (q) for (jj=j; jj<=y; jj++) if (s[ii][jj]=='1') q=false;
    if (q) r=(x-i+y-j+2)*2;
  }
  printf("%d\n",r);
  return 0;
}