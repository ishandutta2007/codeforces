#include <cstdio>
#include <memory.h>
using namespace std;

int main() {
 int n;
 scanf("%d",&n);
 bool a[3002];
 memset(a,false,sizeof(a));
 for (int i=0; i<n; i++)
  { int k; scanf("%d",&k); a[k] = true; }
 for (int i=1; i<=3001; i++)
  if (!a[i]) { printf("%d",i); return 0;}
}