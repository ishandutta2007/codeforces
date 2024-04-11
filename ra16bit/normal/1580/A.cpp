#include <bits/stdc++.h>
using namespace std;
const int MX=410,inf=1000000;
int t,n,m,i,j,k,mn,res,cur,st[MX],sum[MX],up[MX][MX];
char s[MX][MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) {
      scanf("%s",s[i]+1);
      for (j=1; j<=m; j++) up[i][j]=up[i-1][j]+s[i][j]-'0';
    }
    res=inf;
    for (i=1; i<=n; i++) for (j=i+4; j<=n; j++) {
      mn=inf;
      for (k=1; k<=m; k++) {
        cur=up[j-1][k]-up[i][k];
        sum[k]=sum[k-1]+cur+int(s[i][k]=='0')+int(s[j][k]=='0');
        st[k]=j-i-1-cur;
        if (k>=4) {
          mn=min(mn,st[k-3]);
          res=min(res,st[k]+sum[k-1]+mn);
        }
        st[k]-=sum[k];
      }
    }
    printf("%d\n",res);
  }
  return 0;
}