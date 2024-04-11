#include <stdio.h>
int n,i,j,k,r;
bool a[5555];
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) if (!a[i]) for (j=2*i; j<=n; j+=i) a[j]=true;
  for (i=2; i<=n; i++) {
    k=0;
    for (j=2; j<=i; j++) if (i%j==0 && !a[j]) k++;
    if (k==2) r++;
  }
  printf("%d\n",r);
  return 0;
}