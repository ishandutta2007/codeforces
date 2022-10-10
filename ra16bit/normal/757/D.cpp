#include <cstdio>
using namespace std;
const int MK=20,md=1000000007;
int n,ii,i,j,nj,e,cur,r,nx[77],f[77][(1<<20)+5];
char s[77];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  nx[n]=n;
  for (i=n-1; i>=0; i--) if (s[i]=='1') nx[i]=i; else nx[i]=nx[i+1];
  for (i=0; i<n; i++) {
    f[i][0]=(f[i][0]+1)%md;
    ii=nx[i];
    for (j=0; j<(1<<MK); j++) if (f[i][j]) {
      for (cur=0, e=0; e<5 && ii+e<n; e++) {
        cur=cur*2+s[ii+e]-'0';
        if (cur>0 && cur<=MK) {
          nj=(j|(1<<(cur-1)));
          f[ii+e+1][nj]=(f[ii+e+1][nj]+f[i][j])%md;
        }
      }
    }
  }
  for (i=1; i<=n; i++)
    for (j=1; j<=MK; j++)
      r=(r+f[i][(1<<j)-1])%md;
  printf("%d\n",r);
  return 0;
}