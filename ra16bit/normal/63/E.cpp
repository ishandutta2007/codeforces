#include <stdio.h>
#include <memory.h>
const int dx[3]={0,1,1};
const int dy[3]={1,0,1};
int i,j,k,a[7][7],x[22],y[22],z,p,xx,yy;
bool f[555555];
char s[5];
int main() {
  memset(a,255,sizeof(a));
  for (i=0; i<3; i++) for (j=0; j<3+i; j++) {
    a[i][j]=k++;
    x[a[i][j]]=i;
    y[a[i][j]]=j;
  }
  for (i=0; i<2; i++) for (j=0; j<3+i; j++) {
    a[4-i][4-j]=30-(k++);
    x[a[4-i][4-j]]=4-i;
    y[a[4-i][4-j]]=4-j;
  }
  for (i=1; i<(1<<19); i++) for (j=0; j<19; j++) if (i&(1<<j)) {
    for (k=0; k<3 && (!f[i]); k++) {
      xx=x[j]; yy=y[j]; z=(1<<j);
      while (true) {
        f[i]|=(!f[i^z]);
        if (f[i]) break;
        xx+=dx[k];
        yy+=dy[k];
        p=a[xx][yy];
        if (p==-1 || (i&(1<<p))==0) break;
        z|=(1<<p);
      }
    }
    if (f[i]==1) break;
  }
  for (i=j=0; i<19; i++) {
    scanf("%s",s);
    if (s[0]=='O') j|=(1<<i);
  }
  if (f[j]) puts("Karlsson"); else puts("Lillebror");
  return 0;
}