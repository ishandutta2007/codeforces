#include <cstdio>
#include <memory.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,nn,i,j,k,p,r,a[44][44],f[111][111][44];
char s[111],st[5],x,y;
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%d%d",&m,&nn);
  while (nn--) {
    scanf("%s",st); x=st[0];
    scanf("%s",st); y=st[0];
    scanf("%d",&a[x-'a'][y-'a']);
  }
  memset(f,150,sizeof(f));
  for (i=0; i<26; i++) f[1][int(i!=(s[0]-'a'))][i]=max(f[1][int(i!=s[0])][i],0);
  for (i=1; i<n; i++) for (j=0; j<=m; j++) for (k=0; k<26; k++) if (f[i][j][k]>=-1000000000) 
   for (p=0; p<26; p++) f[i+1][j+int(p!=(s[i]-'a'))][p]=max(f[i+1][j+int(p!=(s[i]-'a'))][p],f[i][j][k]+a[k][p]);
  r=-1000000000;
  for (j=0; j<=m; j++) for (k=0; k<26; k++) if (f[n][j][k]>r) r=f[n][j][k];
  printf("%d\n",r);
  return 0;
}