#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,j,mn,pos,a[MX],nxt[MX][28];
long long cur,res,inf;
char s[MX],z[MX];
int fsum(int x) {
  int r=0;
  for (; x>0; x&=x-1) r+=a[x];
  return r;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",z+1);
    for (i=1; i<=n; i++) {
      s[i]-='a';
      z[i]-='a';
    }
    for (j=0; j<26; j++) nxt[n+1][j]=n+1;
    for (i=n; i>=0; i--) {
      for (j=0; j<26; j++) nxt[i][j]=nxt[i+1][j];
      if (i>0) nxt[i][s[i]]=i;
    }
    cur=0;
    res=n;
    res*=res;
    inf=res;
    for (i=0; i<=n; i++) a[i]=0;
    for (i=1; i<=n; i++) {
      mn=n+1;
      for (j=0; j<z[i]; j++) mn=min(mn,nxt[0][j]);
      if (mn<=n) res=min(res,cur+mn-1-fsum(mn-1));
      if ((pos=nxt[0][z[i]])<=n) {
        cur+=pos-1-fsum(pos-1);
        for (j=pos; j<=n; j=(j<<1)-(j&(j-1))) ++a[j];
        nxt[0][z[i]]=nxt[pos+1][z[i]];
      } else break;
    }
    printf("%lld\n",(res==inf)?-1LL:res);
  }
  return 0;
}