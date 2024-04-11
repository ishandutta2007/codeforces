#include <stdio.h>
int i,j,k,n,m,s,t,x,y,a[111],b[111],c[111];
bool q;
int main() {
  b[0]=b[1]=c[0]=c[1]=0;
  scanf("%d%d%d%d",&a[1],&x,&y,&n);
  a[0]=-x; a[1]+=y; m=1;
  for (i=1; i<=n; i++) {
    scanf("%d%d",&t,&s);
    if (t==1) {
      q=true;
      for (j=0; j<m; j++) if (a[j+1]-a[j]-b[j]>=x+y+s) {
        m++; j++;
        for (k=m; k>j; k--) { a[k]=a[k-1]; b[k]=b[k-1]; c[k]=c[k-1]; }
        a[j]=a[j-1]+b[j-1]+x; b[j]=s; c[j]=i;
        printf("%d\n",a[j]);
        q=false; break;
      }
      if (q) puts("-1");
    } else {
      for (j=1; j<m; j++) if (c[j]==s) {
        m--;
        for (k=j; k<=m; k++) { a[k]=a[k+1]; b[k]=b[k+1]; c[k]=c[k+1]; }
        break;
      }
    }
  }
  return 0;
}