#include <cstdio>
#include <cstring>
using namespace std;
int n,m,i,j,l,r,h,it,a[200200],u[200200];
char s[200200],t[200200];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); a[i]--; }
  l=0; r=n-m;
  while (l<r) {
    h=(l+r)/2+1; ++it;
    for (i=0; i<h; i++) u[a[i]]=it;
    for (i=j=0; i<n && j<m; i++) if (u[i]!=it) {
      if (s[i]==t[j]) j++;
    }
    if (j>=m) l=h; else r=h-1;
  }
  printf("%d\n",r);
  return 0;
}