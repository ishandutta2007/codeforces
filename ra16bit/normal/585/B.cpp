#include <stdio.h>
int t,n,m,i,j,k;
char s[3][103];
bool f[103][3],can[3];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<3; i++) f[0][i]=false;
    for (i=0; i<3; i++) {
      scanf("%s",s[i]);
      for (j=0; j<n; j++) if (s[i][j]=='s') f[j][i]=true;
    }
    for (i=0; i<n-1; i++) if (i%3==1) {
      for (j=0; j<3; j++) {
        can[j]=false;
        if (s[j][i]=='.') for (k=j-1; k<=j+1; k++) can[j]|=(k>=0 && k<3 && f[i][k]);
      }
      for (j=0; j<3; j++) f[i+1][j]=(s[j][i+1]=='.' && can[j]);
    } else for (j=0; j<3; j++) f[i+1][j]=(s[j][i+1]=='.' && f[i][j]);
    puts((f[n-1][0] || f[n-1][1] || f[n-1][2])?"YES":"NO");
  }
  return 0;
}