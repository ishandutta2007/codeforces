#include <bits/stdc++.h>
using namespace std;
const int MX=303*303;
int t,it,n,m,num,i,j,r,a[MX],b[MX],u[MX];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d%d",&n,&m);
    num=n*m;
    for (i=0; i<num; i++) {
      scanf("%d",&a[i]);
      b[i]=a[i];
    }
    sort(b,b+num);
    for (r=i=0; i<num; i++) {
      for (j=num-1; j>=0; --j) if (b[j]==a[i] && u[j]!=it) break;
      u[j]=it;
      for (--j; j>=0; --j) r+=int(u[j]==it);
    }
    printf("%d\n",r);
  }
  return 0;
}