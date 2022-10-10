#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,cur,res,le[505],e[505][505];
char s[505][505];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (res=i=0; i<n; i++) {
      scanf("%s",s[i]);
      for (cur=j=0; j<m; j++) if (s[i][j]=='.') le[j]=cur=0; else le[j]=++cur;
      for (cur=0, j=m-1; j>=0; j--) if (s[i][j]=='.') e[i][j]=cur=0; else {
        ++cur;
        if (i==0) e[i][j]=1; else e[i][j]=min(e[i-1][j]+1,min(le[j],cur));
        res+=e[i][j];
      }
    }
    printf("%d\n",res);
  }
  return 0;
}