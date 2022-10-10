#include <stdio.h>
int n,m,i,j,k,cur,num,b[100100][26],f[100100][2];
char s[100100];
void dfs(int i, int d) {
  f[i][0]=f[i][1]=(d&1);
  bool q=true;
  for (int j=0; j<26; j++) if (b[i][j]) {
    q=false;
    dfs(b[i][j],d+1);
    if (d&1) {
      f[i][0]&=f[b[i][j]][0];
      f[i][1]&=f[b[i][j]][1];
    } else {
      f[i][0]|=f[b[i][j]][0];
      f[i][1]|=f[b[i][j]][1];
    }
  }
  if (q) {
    if (d&1) f[i][0]=false; else f[i][0]=true;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    for (j=k=0; s[j]; j++) {
      cur=s[j]-'a';
      if (b[k][cur]==0) b[k][cur]=++num;
      k=b[k][cur];
    }
  }
  dfs(0,0);
  puts((f[0][1] && (f[0][0] || (m&1)))?"First":"Second");
  return 0;
}