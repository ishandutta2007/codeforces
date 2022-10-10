#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,r,ls[5005][5005],f[5005];
char s[5005];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    for (i=n-1; i>=0; i--) for (j=i+1; j<n; j++) {
      if (s[i]<s[j]) ls[i][j]=j;
        else if (s[i]==s[j] && j+1<n) ls[i][j]=ls[i+1][j+1];
          else ls[i][j]=0;
    }
    f[0]=r=n;
    for (i=1; i<n; i++) {
      f[i]=n-i;
      for (j=i-1; j>=0; j--) if (ls[j][i]) f[i]=max(f[i],f[j]+n-ls[j][i]);
      r=max(r,f[i]);
    }
    printf("%d\n",r);
  }
  return 0;
}