#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,i,j,le,ri,len,res,s[MX][19];
int main() {
  for (i=1; i<MX; i++) for (j=0; j<19; j++) {
    s[i][j]=s[i-1][j];
    if ((i>>j)&1) ++s[i][j];
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&le,&ri);
    res=ri-le;
    --le;
    len=ri-le;
	for (i=0; i<19; i++) res=min(res,len-s[ri][i]+s[le][i]);
    printf("%d\n",res);
  }
  return 0;
}