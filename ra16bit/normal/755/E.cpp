#include <cstdio>
using namespace std;
int n,i,m;
int main() {
  scanf("%d%d",&n,&m);
  if (m==2) {
    if (n>4) {
      printf("%d\n",n-1);
      for (i=1; i<n; i++) printf("%d %d\n",i,i+1);
    } else puts("-1");
  } else if (m==3) {
    if (n>3) {
      printf("%d\n2 3\n",n-1);
      for (i=3; i<=n; i++) printf("1 %d\n",i);
    } else puts("-1");
  } else puts("-1");
  return 0;
}