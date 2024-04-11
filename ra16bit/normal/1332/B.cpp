#include <bits/stdc++.h>
using namespace std;
const int p[11]={2,3,5,7,11,13,17,19,23,29,31};
int t,it,n,m,i,j,x,a[1010],b[11],was[11];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d",&n);
    for (m=i=0; i<n; i++) {
      scanf("%d",&x);
      for (j=0; j<11; j++) if (x%p[j]==0) {
        if (was[j]!=it) {
          b[j]=++m;
          was[j]=it;
        }
        a[i]=b[j];
        break;
      }
    }
    printf("%d\n",m);
    for (i=0; i<n; i++) printf("%d ",a[i]);
    puts("");
  }
  return 0;
}