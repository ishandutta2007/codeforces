#include <bits/stdc++.h>
using namespace std;
const int MX=22000;
int t,i,j,n,s,a[202];
bool u[MX];
int main() {
  for (i=2; i<MX; i++) if (!u[i]) for (j=i+i; j<MX; j+=i) u[j]=true;
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (s=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      s+=a[i];
    }
    if (u[s]) {
      printf("%d\n",n);
      for (j=1; j<=n; j++) printf("%d ",j);
    } else for (i=0; i<n; i++) if (u[s-a[i]]) {
      printf("%d\n",n-1);
      for (j=1; j<=i; j++) printf("%d ",j);
      for (j=i+2; j<=n; j++) printf("%d ",j);
      break;
    }
    puts("");
  }
  return 0;
}