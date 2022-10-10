#include <stdio.h>
#include <string.h>
int i,j,n,e,M,m[3];
char s[3][777],t[777],st[777];
bool u[3],q;
void rec(int i, int p) {
  if (i==3) { q=true; return; }
  int j,e;
  for (j=0; j<3; j++) if (!u[j]) {
    for (e=0; p+e<M && e<m[j]; e++) if (s[j][e]!=t[p+e]) break;
    if (e==m[j] && p+e<=M) {
      u[j]=true;
      rec(i+1,p+e);
      u[j]=false;
      if (q) return;
    }
  }
}
int main() {
  for (j=0; j<3; j++) {
    scanf("%s",st); n=strlen(st);
    for (i=0; i<n; i++) if (st[i]>='A' && st[i]<='Z') s[j][m[j]++]=st[i]-'A'+'a';
      else if (st[i]>='a' && st[i]<='z') s[j][m[j]++]=st[i];
  }
  scanf("%d",&e);
  for (j=0; j<e; j++) {
    scanf("%s",st); n=strlen(st); M=0;
    for (i=0; i<n; i++) if (st[i]>='A' && st[i]<='Z') t[M++]=st[i]-'A'+'a'; 
      else if (st[i]>='a' && st[i]<='z') t[M++]=st[i];
    q=false;
    rec(0,0);
    if (q) puts("ACC"); else puts("WA");
  }
  return 0;
}