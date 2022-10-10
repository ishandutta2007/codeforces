#include <stdio.h>
#include <string.h>
int n,m,r,c,i,j,k,cur,nx,res,w,a[1000100],b[20][1000100],st[1000100];
char s[5000100];
int main() {
  scanf("%d%d%d",&n,&r,&c);
  for (i=0; i<n; i++) {
    st[i]=m;
    scanf("%s",s+m);
    a[i]=strlen(s+m);
	m+=a[i];
  }
  for (i=0; i<n; i++) {
    if (i==0 || b[0][i-1]<=i) {
	  b[0][i]=i;
	  cur=0;
	} else {
	  b[0][i]=b[0][i-1];
	  cur-=a[i-1]+1;
	}
	while (b[0][i]<n) {
	  nx=cur;
	  if (nx>0) nx++;
	  nx+=a[b[0][i]];
	  if (nx>c) break;
	  cur=nx;
	  b[0][i]++;
	}
  }
  b[0][n]=n;
  for (j=1; j<20; j++) for (i=0; i<=n; i++) b[j][i]=b[j-1][b[j-1][i]];
  for (i=0; i<=n; i++) {
    cur=r; nx=i;
    for (j=19; j>=0; j--) if (cur>=(1<<j)) {
	  cur-=1<<j;
	  nx=b[j][nx];
	}
	if (nx-i>res) {
	  res=nx-i;
	  w=i;
	}
  }
  for (i=0; i<r; i++) {
    for (j=w; j<b[0][w]; j++) {
	  if (j!=w) putchar(' ');
	  for (k=0; k<a[j]; k++) putchar(s[st[j]+k]);
	}
	putchar('\n');
	w=b[0][w];
  }
  return 0;
}