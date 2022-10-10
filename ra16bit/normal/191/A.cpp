#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,i,j,x,y,m,r,a[26][26];
char s[22];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    m=strlen(s);
    x=s[0]-'a';
    y=s[m-1]-'a';
    for (j=0; j<26; j++) if (a[j][x]) a[j][y]=max(a[j][y],a[j][x]+m);
    a[x][y]=max(a[x][y],m);
    r=max(r,a[y][y]);
  }
  printf("%d\n",r);
  return 0;
}