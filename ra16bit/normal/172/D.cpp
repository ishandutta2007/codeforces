#include <stdio.h>
const int MX=20000010;
int i,j,l,r,b[MX];
bool a[MX];
long long k;
int main() {
  scanf("%d%d",&l,&r); r+=l;
  for (i=0; i<r; i++) b[i]=1;
  for (i=2; i*i<r; i++) if (!a[i]) {
    for (j=i+i; j<r; j+=i) a[j]=true;
    for (j=k=i*i; j<r; j+=k) while (j%(b[j]*k)==0) b[j]*=k;
  }
  for (k=0, i=l; i<r; i++) k+=i/b[i];
  printf("%I64d\n",k);
  return 0;
}