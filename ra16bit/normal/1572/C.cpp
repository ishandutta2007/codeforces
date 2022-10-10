#include <bits/stdc++.h>
using namespace std;
const int MX=3003;
int t,n,i,j,len,num,pos,prv,now,a[MX],b[MX],f[MX][MX];
vector<int> g[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) g[i].clear();
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      b[i]=g[a[i]].size();
      g[a[i]].push_back(i);
    }
    for (len=1; len<n; len++) for (i=1; i+len<=n; i++) {
      j=i+len;
      f[i][j]=max(f[i+1][j],f[i][j-1]);
      if (a[i]==a[j]) f[i][j]=max(f[i][j],f[i+1][j-1]+1);
      num=g[a[i]].size();
      prv=i;
      for (pos=b[i]+1; pos<num && (now=g[a[i]][pos])<j; pos++) {
        f[i][j]=max(f[i][j],f[i][now]+f[now][j]);
        prv=now;
      }
      //printf("%d %d = %d\n",i,j,f[i][j]);
    }
    printf("%d\n",n-1-f[1][n]);
  }
  return 0;
}