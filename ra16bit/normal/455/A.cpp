#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a;
long long c[100100],f[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a); c[a]++; }
  f[1]=c[1];
  for (i=2; i<=100002; i++) f[i]=max(f[i-1],f[i-2]+c[i]*i);
  printf("%I64d\n",f[100002]);
  return 0;
}