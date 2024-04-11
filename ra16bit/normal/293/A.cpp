#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,x,y,z,a[2][2];
char s[2000200],t[2000200];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  scanf("%s",t);
  for (i=0; i<2*n; i++) a[s[i]-'0'][t[i]-'0']++;
  y=a[1][1]/2; x=a[1][1]-y;
  if (a[1][1]%2) {
    if (a[0][1]>0) { a[0][1]--; y++; } else if (a[1][0]>0) a[1][0]--;
  }
  z=min(a[1][0],a[0][1]);
  x+=z; y+=z;
  a[1][0]-=z;
  a[0][1]-=z;
  for (i=0; i<a[1][0]; i+=2) x++;
  for (i=1; i<a[0][1]; i+=2) y++;
  if (x==y) puts("Draw"); else puts(x>y?"First":"Second");
  return 0;
}