#include <stdio.h>
int n,l,i,j,k;
long long cur,res;
long long nod(long long a, long long b) {
  return b==0?a:nod(b,a%b);
}
int main() {
  scanf("%d",&n);
  l=n-10;
  if (l<1) l=1;
  for (i=l; i<=n; i++) for (j=i; j<=n; j++) for (k=j; k<=n; k++) {
    cur=i;
    if (j>i) cur*=j/nod(cur,j);
    if (k>j) cur*=k/nod(cur,k);
    if (cur>res) res=cur;
  }
  printf("%I64d\n",res);
  return 0;
}