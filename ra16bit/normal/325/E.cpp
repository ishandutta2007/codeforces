#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,a[100100],u[100100];
bool w[100100];
int main() {
  scanf("%d",&n);
  if (n&1) { puts("-1"); return 0; }
  for (i=0; i<n; i++) a[i]=(i*2+int(i*2<n))%n;
  for (k=0; k<n; k++) if (!u[k]) {
    m++;
    for (i=k, j=0; !u[i]; j++) {
      u[i]=m;
      i=a[i];
    }
  }
  w[1]=true;
  printf("0 ");
  for (i=a[0]; i!=0; i=a[i]) {
    printf("%d ",i);
    j=(i+n/2)%n;
    if (!w[u[j]]) {
      swap(a[i],a[j]);
      w[u[j]]=true;
    }
  }
  puts("0");
  return 0;
}