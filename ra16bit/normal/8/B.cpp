#include <cstdio>
#include <cstring>
using namespace std;
char s[110];
int a[250][250],n,x,y,i;
int main() {
  gets(s); n=strlen(s);
  x=125; y=125;
  for (i=0; i<n; i++) {
    a[x][y]=1;
    if (s[i]=='L') x++;
    if (s[i]=='R') x--;
    if (s[i]=='U') y++;
    if (s[i]=='D') y--;
    if (a[x][y]==1 || (a[x+1][y]+a[x-1][y]+a[x][y+1]+a[x][y-1]>1)) { puts("BUG"); return 0; }
  }
  puts("OK");
  return 0;
}