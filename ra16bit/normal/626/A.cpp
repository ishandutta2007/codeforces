#include <bits/stdc++.h>
using namespace std;
int n,i,j,x,y,r;
char s[202];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<n; i++) {
    x=y=0;
    for (j=i; j<n; j++) {
      if (s[j]=='U') x++;
      if (s[j]=='D') x--;
      if (s[j]=='R') y++;
      if (s[j]=='L') y--;
      if (x==0 && y==0) r++;
    }
  }
  printf("%d\n",r);
  return 0;
}