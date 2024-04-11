#include <stdio.h>
int l,r;
long long ll,s,p,i,j;
int main() {
  scanf("%d%d",&l,&r);
  for (i=5,j=9; i<=r; i*=10,j=(j+1)*10-1) if (i>=l && i<=r && i*(j-i)>s) s=i*(j-i);
  for (ll=l, j=9; l>9; l/=10) j=(j+1)*10-1;
  if (ll*(j-ll)>s) s=ll*(j-ll);
  for (ll=r, j=9; r>9; r/=10) j=(j+1)*10-1;
  if (ll*(j-ll)>s) s=ll*(j-ll);
  printf("%I64d\n",s);
  return 0;
}