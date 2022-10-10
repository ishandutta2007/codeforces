#include <stdio.h>
int i,j,x,y,z,a[111][111],b[2][111],c[2],d[2][111],e[2];
int main() {
  scanf("%d%d",&c[0],&c[1]);
  for (i=0; i<c[0]; i++) for (j=0; j<c[1]; j++) {
    scanf("%d",&a[i][j]);
	b[0][i]+=a[i][j];
	b[1][j]+=a[i][j];
  }
  while (true) {
    x=y=0; z=b[0][0];
    for (i=0; i<2; i++) for (j=0; j<c[i]; j++)  if (b[i][j]<z) { x=i; y=j; z=b[i][j]; }
	if (z>=0) break;
	if (x==0) for (i=0; i<c[1]; i++) {
	  a[y][i]=-a[y][i];
	  b[0][y]+=2*a[y][i];
	  b[1][i]+=2*a[y][i];
	} else for (i=0; i<c[0]; i++) {
	  a[i][y]=-a[i][y];
	  b[0][i]+=2*a[i][y];
	  b[1][y]+=2*a[i][y];
	}
	d[x][y]^=1;
  }
  for (i=0; i<2; i++) for (j=0; j<c[i]; j++) if (d[i][j]) e[i]++;
  for (i=0; i<2; i++) {
    printf("%d",e[i]);
	for (j=0; j<c[i]; j++) if (d[i][j]) printf(" %d",j+1);
	puts("");
  }
  return 0;
}