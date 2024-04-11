#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,e,i,j,l,f[10010],a[10010],c[10010];
char s[10010];
int main() {
  scanf("%d",&m); gets(s);
  gets(s); n=strlen(s);
  for (i=0; i<n; i++) if (s[i]=='.' || s[i]=='?' || s[i]=='!') {
    if (i-l+1>m) { puts("Impossible"); return 0; }
    a[++e]=i-l+1;
    c[e]=c[e-1]+a[e];
    f[e]=1000000; l=i+2;
  }
  for (i=0; i<e; i++) for (j=i+1; j<=e; j++) if (c[j]-c[i]+j-i-1<=m) f[j]=min(f[j],f[i]+1);
  printf("%d\n",f[e]);
  return 0;
}