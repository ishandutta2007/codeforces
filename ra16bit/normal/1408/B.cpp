#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,c,a[111];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (c=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (i==0 || a[i]>a[i-1]) c++;
    }
    if (m==1) {
      puts((c==1)?"1":"-1");
      continue;
    }
    if (c<=m) {
      puts("1");
      continue;
    }
    printf("%d\n",1+(c-2)/(m-1));
  }
  return 0;
}