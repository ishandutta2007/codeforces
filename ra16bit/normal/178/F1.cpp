#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MN=102,MB=502*102;
int n,m,i,j,k,p,e,cur,len,num,a[MB],b[MB][26],stop[MB],f[MB][MN],r[MB][MN];
char s[502];
void dfs(int i) {
  if (a[i]+stop[i]<2) return;
  int pred=-1,tot=0,j,k;
  for (j=0; j<26; j++) if (k=b[i][j]) {
    dfs(k);
    cur=a[k]+stop[k];
    for (e=0; e<=tot && e<=m; e++) for (p=0; p<=cur && p+e<=m; p++) f[k][e+p]=max(f[k][e+p],f[pred][e]+r[k][p]);
    //if (i==0) printf("f %d %d = %d\n",k,e+p,f[k][e+p]);
    pred=k;
    tot+=cur;
  }
  for (e=1; e<=tot+stop[i]; e++) r[i][e]=e<=tot?f[pred][e]:r[i][e-1];
  if (i>0) for (e=1; e<=tot+stop[i]; e++) r[i][e]+=(e*(e-1))/2;
    //printf("r    %d %d = %d\n",i,e,r[i][e]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    len=strlen(s);
    for (j=k=0; j<len; j++) {
      a[k]++;
      cur=s[j]-'a';
      if (b[k][cur]==0) b[k][cur]=++num;
      k=b[k][cur];
    }
    stop[k]++;
  }
  dfs(0);
  printf("%d\n",r[0][m]);
  return 0;
}