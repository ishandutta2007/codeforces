#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int e,n,m,i,j,k,r,x,sk,a[25][25],b[25],f[1<<22],t[25];
pair <int, int> c[25];
char s[200200];
int main() {
  scanf("%d%d%d",&e,&n,&m);
  scanf("%s",s);
  for (i=0; i<n; i++) scanf("%d",&t[i]);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
  for (i=0; i<n; i++) b[i]=-1;
  for (k=0; k<e; k++) {
    for (i=0; i<n; i++) c[i]=make_pair(-b[i],i);
    sort(c,c+n); sk=s[k]-'A';
    for (i=j=0; i<n && c[i].first<=0; i++) {
      f[j]+=a[c[i].second][sk];
      f[j|(1<<sk)]-=a[c[i].second][sk];
      f[j|(1<<c[i].second)]-=a[c[i].second][sk];
      f[j|(1<<c[i].second)|(1<<sk)]+=a[c[i].second][sk];
      if (c[i].second==sk) break; else j|=(1<<c[i].second);
    }
    x|=(1<<sk); b[sk]=k;    
  }
  for (j=0; j<n; j++) for (i=0; i<(1<<n); i++) if (i&(1<<j)) f[i]+=f[i^(1<<j)];
  for (i=0; i<(1<<n); i++) for (j=0; j<n; j++) if (i&(1<<j)) f[i]+=t[j];
  for (i=0; i<(1<<n); i++) if ((i|x)==x && i<x && f[i]<=m) r++;
  printf("%d\n",r);
  return 0;
}