#include <cstdio>
using namespace std;

int main() {
 int n; scanf("%d",&n);
 bool a[5001]; for (int i=0;i<=5000;i++) a[i]=false;
 for (int i=0;i<n;i++)
  { int x;scanf("%d",&x); a[x]=true; }
 int res=0;
 for (int i=1;i<=n;i++)
  if (!a[i]) res++;
 printf("%d",res);
 return 0;
 }