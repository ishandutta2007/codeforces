#include <stdio.h>
#include <string.h>
int n,k,i,j,z,x,m,p[111],g[111][111];
char a[111],s[111],t[111],c[111][111];
bool f[111][111],q;
int find(int i, char c) {
  while (i>0 && s[i]!=c) i=p[i-1];
  if (s[i]==c) i++;
  return i;
}
int main() {
  scanf("%d%d",&n,&k);
  scanf("%s",s); m=strlen(s);
  for (i=1; i<m; i++) p[i]=find(p[i-1],s[i]);
  scanf("%s",t); q=true;
  for (i=0; i<=n-m; i++) if (t[i]=='1') for (j=0; j<m; j++) {
    if (a[i+j]!=0 && a[i+j]!=s[j]) q=false;
    a[i+j]=s[j];
  }
  if (!q) { puts("No solution"); return 0; } else f[0][0]=true;
  for (i=0; i<n; i++) for (j=0; j<=m; j++) if (f[i][j] && (j<m || (i>=m && t[i-m]=='1'))) {
    if (a[i]==0) for (x=0; x<k; x++) {
      z=find(j,'a'+x);
      f[i+1][z]=true;
      g[i+1][z]=j;
      c[i+1][z]='a'+x;
    } else {
      z=find(j,a[i]);
      f[i+1][z]=true;
      g[i+1][z]=j;
      c[i+1][z]=a[i];
    }
  }
  for (j=0; j<=m; j++) if (f[n][j] && (j<m || (n>=m || t[n-m]=='1'))) {
    for (i=n; i>0; i--) {
      a[i-1]=c[i][j];
      j=g[i][j];
    }
    puts(a);
    return 0;
  }
  puts("No solution");
  return 0;
}