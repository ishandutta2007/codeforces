#include <cstdio>
#include <cstring>
using namespace std;
int n,m,x,y,i,d,e,r,z,j,q[26],g[26][26];
char s[111111],t[111111],c;
int main() {
  gets(s); n=strlen(s);
  gets(t); m=strlen(t);
  if (n!=m) { puts("-1"); return 0; }
  scanf("%d",&m);
  for (i=0; i<26; i++) {
    for (j=0; j<26; j++) g[i][j]=1000000000;
    g[i][i]=0;
  }
  for (i=0; i<m; i++) {
    for (c='.'; c<'a' || c>'z'; c=getchar()); x=c-'a';
    for (c='.'; c<'a' || c>'z'; c=getchar()); y=c-'a';
    scanf("%d",&z);
    if (z<g[x][y]) g[x][y]=z;
  }
  for (z=0; z<26; z++) for (i=0; i<26; i++) for (j=0; j<26; j++)
    if (g[i][z]+g[z][j]<g[i][j]) g[i][j]=g[i][z]+g[z][j];
  for (i=0; i<n; i++) if (s[i]!=t[i]) {
    d=1000000000; e=-1;
    x=s[i]-'a'; y=t[i]-'a';
    for (j=0; j<26; j++) if (g[x][j]+g[y][j]<d) { d=g[x][j]+g[y][j]; e=j; }
    if (e==-1) { puts("-1"); return 0; }
    r+=d; s[i]='a'+e;
  }
  printf("%d\n",r);
  puts(s);
  return 0;
}