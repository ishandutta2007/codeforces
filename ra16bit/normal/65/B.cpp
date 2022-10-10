#include <stdio.h>
int n,i,a,j,x,e,k,b[2222][4],z[4],r[1111];
bool q=true;
int main() {
  for (i=1000; i<=2011; i++) {
    x=i;   b[i][0]=x%10; 
    x/=10; b[i][1]=x%10;
    x/=10; b[i][2]=x%10;
    x/=10; b[i][3]=x%10; 
  }
  scanf("%d",&n); x=1000;
  for (i=0; i<n; i++) {
    scanf("%d",&a); z[0]=a%10;
    a/=10; z[1]=a%10;
    a/=10; z[2]=a%10;
    a/=10; z[3]=a%10;
    for (j=x; j<=2011; j++) {
      for (e=k=0; k<4; k++) if (z[k]!=b[j][k]) e++;
      if (e<=1) break;
    }
    x=r[i]=j;
    if (j>2011) q=false;
  }
  if (q) for (i=0; i<n; i++) printf("%d\n",r[i]); else puts("No solution");
  return 0;
}