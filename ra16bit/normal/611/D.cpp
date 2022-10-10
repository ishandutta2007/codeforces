#include <stdio.h>
const int md=1000000007;
int n,i,j,k,r,a[5005][5005],f[5005][5005];
char s[5005];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (j=n-2; j>=0; j--) a[n-1][j]=int(s[j]==s[n-1]);
  for (i=n-2; i>=0; i--) for (j=i-1; j>=0; j--)
    if (s[i]==s[j]) a[i][j]=1+a[i+1][j+1];
  f[1][0]=1;
  for (i=1; i<n; i++) for (j=0; j<i; j++) {
    f[i+1][j]+=f[i][j];
    if (f[i+1][j]>=md) f[i+1][j]-=md;
    k=i+i-j;
    if (s[i]!='0' && k<=n) {
      if (i+a[i][j]<k && s[j+a[i][j]]<s[i+a[i][j]]) {
        f[k][i]+=f[i][j];
        if (f[k][i]>=md) f[k][i]-=md;
      } else if (k+1<=n) {
        f[k+1][i]+=f[i][j];
        if (f[k+1][i]>=md) f[k+1][i]-=md;
      }
    }
  }
  for (i=0; i<n; i++) {
    r+=f[n][i];
    if (r>=md) r-=md;
  }
  printf("%d\n",r);
  return 0;
}