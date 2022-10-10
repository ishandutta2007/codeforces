#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,c,a[100100],b[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); b[i]=a[i]; }
  sort(a,a+n);
  for (i=0; i<n; i++) if (a[i]!=b[i]) c++;
  puts(c<3?"YES":"NO");
  return 0;
}