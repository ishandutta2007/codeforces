#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,f[1000100];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++)
    for (f[i]=j=i; j>0; j/=10) if (j!=0) f[i]=min(f[i],f[i-j%10]+1);
  printf("%d\n",f[n]);
  return 0;
}