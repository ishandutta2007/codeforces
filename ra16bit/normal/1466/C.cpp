#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,k,nxt,r,f[100100][2][2];
char s[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s+1);
    n=strlen(s+1);
    if (n==1) { puts("0"); continue; }
    for (i=0; i<=n; i++) for (j=0; j<2; j++) for (k=0; k<2; k++) f[i][j][k]=n+1;
    for (j=0; j<2; j++) for (k=0; k<2; k++) if (j==1 || k==1 || s[1]!=s[2]) f[2][j][k]=j+k;
    for (i=2; i<n; i++) for (j=0; j<2; j++) for (k=0; k<2; k++) if (f[i][j][k]<=n)
      for (nxt=0; nxt<2; nxt++) {
        if (j==0 && nxt==0 && s[i-1]==s[i+1]) continue;
        if (k==0 && nxt==0 && s[i]==s[i+1]) continue;
        f[i+1][k][nxt]=min(f[i+1][k][nxt],f[i][j][k]+nxt);
      }
    for (r=n, j=0; j<2; j++) for (k=0; k<2; k++) r=min(r,f[n][j][k]);
    printf("%d\n",r);
  }
  return 0;
}