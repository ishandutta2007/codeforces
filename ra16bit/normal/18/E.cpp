#include <stdio.h>
int i,j,k,n,m,t,z,a,b,x,y,dd,ee,f[505][30][30];
char s[505][505],d[505][30][30],e[505][30][30];
int main() {
  scanf("%d%d",&n,&m); gets(s[0]);
  for (i=0; i<n; i++) gets(s[i]);
  for (i=0; i<26; i++) for (j=0; j<26; j++) if (i!=j) for (k=0; k<m; k++) 
    if (k&1) f[0][i][j]+=int(s[0][k]!='a'+j); else f[0][i][j]+=int(s[0][k]!='a'+i);
  for (i=1; i<n; i++) for (a=0; a<26; a++) for (b=0; b<26; b++) if (a!=b) {
    z=0; t=1000000;
    for (j=0; j<m; j++) if (j&1) z+=int(s[i][j]!=char('a'+b)); else z+=int(s[i][j]!=char('a'+a));
    for (x=0; x<26; x++) if (x!=a) for (y=0; y<26; y++) if (y!=x && y!=b && f[i-1][x][y]<t) {
      t=f[i-1][x][y];
      dd=x; ee=y;
    }
    f[i][a][b]=t+z;
    d[i][a][b]=dd;
    e[i][a][b]=ee;
  }
  t=1000000;
  for (a=0; a<26; a++) for (b=0; b<26; b++) if (a!=b && f[n-1][a][b]<t) { t=f[n-1][a][b]; dd=a; ee=b; }
  printf("%d\n",t);
  for (i=n-1; ; i--) {
    for (j=0; j<m; j++) if (j&1) s[i][j]='a'+ee; else s[i][j]='a'+dd;
    if (i==0) break;
    j=d[i][dd][ee];
    ee=e[i][dd][ee];
    dd=j;
  }
  for (i=0; i<n; i++) puts(s[i]);
  return 0;
}