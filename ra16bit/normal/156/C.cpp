#include <stdio.h>
#include <string.h>
int t,i,j,jj,k,n,m,r,cur,f[102][2503],md=1000000007;
char s[102];
int main() {
  f[0][0]=1;
  for (i=0; i<100; i++) for (j=0; j<=2500; j++) if (f[i][j]) {
    //printf("%d %d = %d %d\n",i,jj,f[i][j],f[1][46]);
    for (k=0; k<26; k++) f[i+1][j+k]=(f[i+1][j+k]+f[i][j])%md;
      /*cur=s[i+1]+jj-k;
      printf("to %d\n",cur);
      if (cur>-26 && cur<26) f[i+1][26+cur]=(f[i+1][26+cur]+f[i][j])%md;
    }*/
    //if (i<3) printf("%d %d = %d\n",i,j,f[i][j]);
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (m=i=0; i<n; i++) m+=s[i]-'a';
    printf("%d\n",(f[n][m]+md-1)%md);
  }
  return 0;
}