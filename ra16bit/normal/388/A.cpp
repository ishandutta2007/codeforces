#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,r,a[111],b[111];
bool u[111];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) {
    k=-1;
    for (j=0; j<i; j++) if (!u[j] && b[j]<=a[i] && (k==-1 || b[j]>b[k])) k=j;
    if (k>=0) {
      u[k]=true;
      b[i]=b[k]+1;
    } else b[i]=1;
  }
  for (i=0; i<n; i++) if (!u[i]) r++;
  printf("%d\n",r);
  return 0;
}