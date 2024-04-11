#include <cstdio>
#include <algorithm>
using namespace std;
const int M=10002;
int n,a,i,j,b[M+1],s[100100],r=200000000;
int main() {
  scanf("%d",&n);
  for (i=1; i<=M; i++) b[i]=10000;
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    s[i]=s[i-1]+a;
    for (j=1; j<=M && i-j>0; j++) b[j]=min(b[j],abs(s[i]-s[i-j]));
  }
  for (j=1; j<=M; j++) r=min(r,j*j+b[j]*b[j]);
  printf("%d\n",r);
  return 0;
}