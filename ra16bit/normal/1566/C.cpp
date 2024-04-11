#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,x,lst[2],f[MX];
char a[MX],b[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    lst[0]=lst[1]=-1;
    for (i=0; i<n; i++) if (a[i]==b[i]) {
      x=int(a[i]=='0');
      f[i+1]=f[i]+x;
      if (lst[x]>=0) f[i+1]=max(f[i+1],f[lst[x]]+2);
      lst[x^1]=i;
    } else f[i+1]=f[i]+2;
    printf("%d\n",f[n]);
  }
  return 0;
}