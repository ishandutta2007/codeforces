#include <stdio.h>
int n,k,m,i;
char s[255][255],r[255][255];
void rec(int xa, int xb, int ya, int yb, int k, int e) {
  int z=e/n,i,j,x,y;
  for (i=0; i<n; i++) for (j=0; j<n; j++) if (s[i][j]=='*') {
    for (x=i*z; x<(i+1)*z; x++) for (y=j*z; y<(j+1)*z; y++) r[xa+x][ya+y]='*';
  } else if (k>1) rec(xa+i*z,xa+(i+z)*z-1,ya+j*z,ya+(j+1)*z-1,k-1,z);
    else for (x=i*z; x<(i+1)*z; x++) for (y=j*z; y<(j+1)*z; y++) r[xa+x][ya+y]='.';
}
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (m=n, i=1; i<k; i++) m*=n;
  rec(0,m-1,0,m-1,k,m);
  for (i=0; i<m; i++) puts(r[i]);
  return 0;
}