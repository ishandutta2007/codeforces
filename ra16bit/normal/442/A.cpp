#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,r,a[111],b[111],x[111],c[1111];
char s[7];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    if (s[0]=='R') a[i]=0;
    if (s[0]=='G') a[i]=1;
    if (s[0]=='B') a[i]=2;
    if (s[0]=='Y') a[i]=3;
    if (s[0]=='W') a[i]=4;
    b[i]=s[1]-'1';
  }
  for (r=10, i=0; i<(1<<10); i++) {
    if (i) c[i]=c[i/2]+(i&1);
    for (j=0; j<n; j++) {
      x[j]=0;
      if ((i>>a[j])&1) x[j]|=1<<a[j];
      if ((i>>(b[j]+5))&1) x[j]|=1<<(b[j]+5);
      for (k=0; k<j; k++) if (x[j]==x[k] && (a[j]!=a[k] || b[j]!=b[k])) break;
      if (k<j) break;
    }
    if (j>=n) r=min(r,c[i]);
  }
  printf("%d\n",r);
  return 0;
}