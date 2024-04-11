#include <bits/stdc++.h>
using namespace std;
int n,best,rst,cur,w,i,j;
char s[111][111];
int main() {
  scanf("%d",&n);
  best=-1;
  for (i=1; i*i<=n; i++) {
    rst=n-i*i;
    if (rst&1) continue;
    rst/=2;
    cur=i+(rst+i-1)/i;
    if (best==-1 || cur<best) {
      best=cur; w=i;
    }
  }
  printf("%d\n",best);
  if (best>0) {
    for (i=0; i<best; i++) for (j=0; j<best; j++) s[i][j]='.';
    for (i=0; i<w; i++) for (j=0; j<w; j++) s[i][j]='o';
    rst=(n-w*w)/2;
    for (i=0; rst>0; i++) for (j=0; j<w && rst>0; j++) {
      s[w+i][j]=s[j][w+i]='o';
      rst--;
    }
  }
  for (i=best-1; i>=0; i--) puts(s[i]);
  return 0;
}