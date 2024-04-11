#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,m,i,j,rgh,r,f[3030][3030];
char s[3030],t[3030];
long long x;
void add(int& x, int y) {
  if ((x+=y)>=md) x-=md;
}
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=0; i<=n; i++) f[0][i]=1;
  for (i=0; i<n; i++) {
    for (j=n; j>0; j--) if (f[i][j]) {
      if (j>m || s[i]==t[j-1]) add(f[i+1][j-1],f[i][j]);
      rgh=i+j;
      if (rgh>=m || s[i]==t[rgh]) add(f[i+1][j],f[i][j]);
    }
    if (f[i][0]) {
      for (j=i; j<n && j<m; j++) if (s[j]!=t[j]) break;
      if (j>=m) add(r,(f[i][0]*(n-j+1LL))%md);
    }
  }
  add(r,f[n][0]);
  printf("%d\n",r);
  return 0;
}