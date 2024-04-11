#include <stdio.h>
int n,i,j,r,x,y,cur,a[2020][2020],b[2020][2020];
char s[2020][2020];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=n-1; i>0; i--) {
    for (j=0; j<n-i; j++) {
	  x=j; y=i+j;
	  a[x][y]=(x==0)?0:a[x-1][y];
	  b[x][y]=(y==n-1)?0:b[x][y+1];
	  if (((a[x][y]+b[x][y])&1)!=((s[x][y]-'0')&1)) {
	    r++; a[x][y]++; b[x][y]++;
	  }
	  x=n-1-j; y=n-1-i-j;
	  a[x][y]=(x==n-1)?0:a[x+1][y];
	  b[x][y]=(y==0)?0:b[x][y-1];
	  if (((a[x][y]+b[x][y])&1)!=((s[x][y]-'0')&1)) {
	    r++; a[x][y]++; b[x][y]++;
	  }
	}
  }
  for (i=0; i<n; i++) {
    cur=((i==0)?0:(a[i-1][i]+b[i][i-1]))+((i==n-1)?0:(a[i+1][i]+b[i][i+1]));
	if ((cur&1)!=((s[i][i]-'0')&1)) r++;
  }
  printf("%d\n",r);
  return 0;
}