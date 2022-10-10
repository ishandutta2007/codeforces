#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int i,j,x,y[1010],z,d,n,m;
char s[1010][1010];
int main() {
  while (scanf("%c",&s[n][0])!=EOF) {
    if (s[n][0]!='\n') gets(s[n]+1); else s[n][0]=0;
    y[n]=strlen(s[n]);
    m=max(m,y[n]); n++;
  }
  for (j=0; j<m+2; j++) putchar('*'); putchar('\n');
  for (i=0; i<n; i++) {
    putchar('*'); x=(m-y[i])/2; z=m-y[i]-x;
    if (z!=x && ((++d)&1)) swap(z,x);
    for (j=0; j<z; j++) putchar(' ');
    for (j=0; j<y[i]; j++) putchar(s[i][j]);
    for (j=0; j<x; j++) putchar(' ');
    putchar('*'); putchar('\n');
  }
  for (j=0; j<m+2; j++) putchar('*'); putchar('\n');
  return 0;
}