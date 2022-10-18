#include <cstdio>

using namespace std;
int n;
int a[300000];
int s = 0;
int ans = 0;

int main() {
 scanf("%d",&n);
 for (int i=0; i<n; i++)
  { scanf("%d",&a[i]); s += a[i]; }
 for (int i=0; i<n; i++)
  if ((s-a[i]) % (n-1) == 0 && (s-a[i])/(n-1) == a[i]) ans++;
  
 printf("%d\n",ans);
 for (int i=0; i<n; i++)
  if ((s-a[i]) % (n-1) == 0 && (s-a[i])/(n-1) == a[i]) printf("%d ",i + 1);
 return 0;
 }