#include <stdio.h>
const int base=10000;
int n,i,j,k,m,a[155],b[555];
bool c[555];
int main() {
  scanf("%d",&n);
  if (n==2) { puts("-1"); return 0; }
  for (i=2; i<555; i++) if (!c[i]) {
    b[m++]=i;
    for (j=i+i; j<555; j+=i) c[j]=true;
  }
  for (i=0; i<n; i++) a[i]=1;
  for (i=0; i<n; i++) {
    for (k=0; k<150; k++) a[k]=0;
    a[0]=a[1]=1;
    for (j=0; j<n; j++) if (j!=i) {
      for (k=1; k<=a[0]; k++) a[k]*=b[j];
      for (k=1; k<=a[0]; k++) if (a[k]>=base) {
        a[k+1]+=a[k]/base; a[k]%=base;
      }
      if (a[a[0]+1]>0) a[0]++;
    }
    printf("%d",a[a[0]]);
    for (k=a[0]-1; k>0; k--) {
      for (j=10; j<base; j*=10) if (j<10) printf("0");
      printf("%d",a[k]);
    }
    printf("\n");
  }
  return 0;
}