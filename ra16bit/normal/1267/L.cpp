#include <bits/stdc++.h>
using namespace std;
int n,m,k,cur,tot,i,j,p,e,z;
char s[1000100],r[1010][1010];
bool u[1000100];
int main() {
  scanf("%d%d%d",&n,&m,&k);
  scanf("%s",s);
  tot=n*m;
  sort(s,s+tot);
  p=-1; cur=k;
  for (i=0; i<m; i++) {
    j=p+cur;
    for (e=j, z=0; e>p && s[e]==s[j]; e--, z++) {
      r[k-1-z][i]=s[e];
      u[e]=true;
    }
    cur=j-e;
    for (; e>p; e--, z++) {
      r[k-1-z][i]=s[e];
      u[e]=true;
    }
    p=j;
  }
  for (i=e=0; i<n; i++) for (j=0; j<m; j++) if (r[i][j]==0) {
    while (u[e]) e++;
    r[i][j]=s[e];
    u[e]=true;
  }
  for (i=0; i<n; i++) puts(r[i]);
  return 0;
}