#include <stdio.h>
#include <string.h>
int n,m,i,j,k,kx,ky,x,y,e,b[555];
char a[555],s[555],tx[22],ty[22],cur,q;
bool g[555][555],can[22];
int gc(char c) { return int(c=='C'); }
bool gg(int i, int j) { return g[i][j^1] || g[j][i^1]; }
bool check(int e, char st) {
  for (int k=0; k<2; k++) {
    can[k]=true;
    b[e]=e*2+k;
    for (int i=0; i<=e; i++) if (gg(b[e],b[i])) { can[k]=false; break; }
  }
  if (!can[0] && !can[1]) return false;
  for (s[e]=st; s[e]<q && !can[gc(a[s[e]-'a'])]; s[e]++);
  if (s[e]>=q) return false;
  b[e]=e*2+gc(a[s[e]-'a']);
  return true;
}
int main() {
  scanf("%s",a);
  q='a'+strlen(a);
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d",&x); x--;
    scanf("%s",tx); kx=gc(tx[0]);
    scanf("%d",&y); y--;
    scanf("%s",ty); ky=gc(ty[0]);
    g[x*2+kx][y*2+ky]=true;
    g[y*2+1-ky][x*2+1-kx]=true;
  }
  scanf("%s",s);
  for (k=0; k<2*n; k++) for (i=0; i<2*n; i++) for (j=0; j<2*n; j++) g[i][j]|=(g[i][k] && g[k][j]);
  for (e=0; e<n; e++) b[e]=e*2+gc(a[s[e]-'a']);
  for (e=0; e<n; e++) {
    for (i=0; i<=e; i++) if (gg(b[e],b[i])) break;
    if (i<=e) break;
  }
  if (e>=n) {
    puts(s);
    return 0;
  }
  for (; e>=0; e--) {
    if (!check(e,s[e]+1)) continue;
    for (j=e+1; j<n; j++) if (!check(j,'a')) { puts("-1"); return 0; }
    puts(s);
    return 0;
  }
  if (e<0) puts("-1");
  return 0;
}