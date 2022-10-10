#include <stdio.h>
const int MX=2000200;
int i,j,k,l,p,q,b[11],c[MX],d[MX];
bool a[MX];
int main() {
  d[1]=1;
  for (i=2; i<MX; i++) {
    c[i]=c[i-1];
    d[i]=d[i-1];
    if (!a[i]) {
      c[i]++;
      for (j=i+i; j<MX; j+=i) a[j]=true;
    }
    for (l=0, k=i; k>0; k/=10, l++) b[l]=k%10;
    for (k=0; k<l; k++) if (b[k]!=b[l-1-k]) break;
    if (k>=l) d[i]++;
  }
  scanf("%d%d",&p,&q);
  for (i=MX-1; i>=0; i--) if (1LL*c[i]*q<=1LL*p*d[i]) {
    printf("%d\n",i);
    return 0;
  }
  return 0;
}