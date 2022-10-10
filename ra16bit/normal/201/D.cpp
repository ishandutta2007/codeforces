#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MB=500,MX=500500,MM=(1<<16)+1;
int n,m,q,cnt,num,i,ii,j,k,cur,mn,best=-1,who,a[MB],b[MB][26],e[MX],nx[MX][17],f[MM][227],mo[MM][17];
char s[17];
int main() {
  scanf("%d",&n);
  mn=(n*(n-1))/2;
  for (i=0; i<n; i++) {
    scanf("%s",s);
    m=strlen(s);
    for (j=k=0; j<m; j++) {
      cur=s[j]-'a';
      if (b[k][cur]==0) b[k][cur]=++num;
      k=b[k][cur];
    }
    a[k]=i+1;
  }
  for (i=0; i<(1<<n); i++) for (cur=0, j=n-1; j>=0; j--) {
    mo[i][j]=cur;
    cur+=((i>>j)&1);
  }
  scanf("%d",&q);
  for (ii=0; ii<q; ii++) {
    scanf("%d",&cnt);
    for (i=0; i<cnt; i++) {
      scanf("%s",s);
      m=strlen(s);
      for (j=k=0; j<m; j++) {
        cur=s[j]-'a';
        if (b[k][cur]==0) break;
        k=b[k][cur];
      }
      if (j>=m) e[i]=a[k]-1; else e[i]=-1;
    }
    for (j=0; j<n; j++) nx[cnt][j]=cnt;
    for (i=cnt-1; i>=0; i--) {
      for (j=0; j<n; j++) nx[i][j]=nx[i+1][j];
      if (e[i]>=0) nx[i][e[i]]=i;
    }
    for (i=0; i<(1<<n); i++) for (j=0; j<=mn; j++) f[i][j]=cnt+1;
    f[0][0]=0;
    for (i=0; i<(1<<n); i++) for (j=0; j<=mn; j++) if (f[i][j]<cnt) {
      for (k=0; k<n; k++) if ((i&(1<<k))==0) {
        int &z=f[i|(1<<k)][j+mo[i][k]];
        z=min(z,nx[f[i][j]][k]+1);
      }
    }
    for (j=0; j<=mn; j++) if (f[(1<<n)-1][j]<=cnt) break;
    if (j<=mn) {
      if (best==-1 || j<best) {
        best=j;
        who=ii;
      }
    }
  }
  if (best>=0) {
    best=mn-best+1;
    printf("%d\n[:",who+1);
    for (i=0; i<best; i++) putchar('|');
    puts(":]");
  } else puts("Brand new problem!");
  return 0;
}