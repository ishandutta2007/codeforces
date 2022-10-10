#include <bits/stdc++.h>
using namespace std;
int n,i,x;
char s[4][111];
int main() {
  scanf("%d",&n);
  for (i=x=0; i+1<n; i+=2, x^=2) {
    s[0][i]='a'+x; s[0][i+1]='a'+x;
    s[1][i]='b'+x; s[1][i+1]='b'+x;
  }
  for (i=1, x=0; i+1<n; i+=2, x^=2) {
    s[2][i]='e'+x; s[2][i+1]='e'+x;
    s[3][i]='f'+x; s[3][i+1]='f'+x;
  }
  s[2][0]='x';
  s[3][0]='x';
  if (n&1) {
    s[0][n-1]='y';
    s[1][n-1]='y';
  } else {
    s[2][n-1]='y';
    s[3][n-1]='y';
  }
  for (i=0; i<4; i++) puts(s[i]);
  return 0;
}