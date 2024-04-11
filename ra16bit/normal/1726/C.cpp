#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,m,res,i,a[MX],p[MX];
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    n*=2;
    for (res=m=i=0; i<n; i++) if (s[i]==')') {
      p[i]=p[a[m]];
      --m;
    } else {
      if (i>0 && s[i-1]==')') p[i]=p[i-1]; else p[i]=++res;
      a[++m]=i;
    }
    printf("%d\n",res);
  }
  return 0;
}