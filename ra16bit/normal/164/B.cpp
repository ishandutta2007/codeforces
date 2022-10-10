#include <stdio.h>
int i,j,l,r,x,res,old,n1,n2,a[2000100],b[2000100];
bool is;
int main() {
  scanf("%d%d",&n1,&n2);
  for (i=1; i<=n1; i++) { scanf("%d",&a[i]); a[n1+i]=a[i]; }
  for (i=1; i<=n2; i++) {
    scanf("%d",&x);
    b[x]=i;
  }
  for (i=1, j=0, old=0; i<=n1; i++) {
    l=b[a[i]];
    if (l==0) { j=0; old=0; is=false; continue; }
    if (old>l) is=false;
    if (j<=i) { j=i; r=l; }
    while (j+1<=2*n1 && b[a[j+1]]!=0) {
      j++;
      if (is) {
        if (b[a[j]]>r && b[a[j]]<l) r=b[a[j]]; else {
          j--;
          break;
        }
      } else {
        if (b[a[j]]>r) r=b[a[j]]; else if (b[a[j]]<l) {
          is=true;
          r=b[a[j]];
        } else {
          j--;
          break;
        }
      }
    }
    if (j-i+1>=res) res=j-i+1;
    old=l;
  }
  printf("%d\n",res);
  return 0;
}