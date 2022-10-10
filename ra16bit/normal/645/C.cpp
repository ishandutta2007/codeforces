#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,l,r,h,x,y,res,a[100100];
char s[100100];
int main() {
  scanf("%d%d",&n,&m);
  m++; res=n;
  scanf("%s",s);
  for (i=1; i<=n; i++) a[i]=a[i-1]+int(s[i-1]=='0');
  for (i=1; i<=n; i++) if (s[i-1]=='0') {
    l=0; r=n;
    while (l<r) {
      h=(l+r)/2;
      x=max(i-h,1);
      y=min(i+h,n);
      if (a[y]-a[x-1]>=m) r=h; else l=h+1;
    }
    res=min(res,r);
  }
  printf("%d\n",res);
  return 0;
}