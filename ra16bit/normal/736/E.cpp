#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MM=3007,MD=MM*2,MX=MD*2;
const char ans[3]={'L','D','W'};
int n,m,mm,i,j,cur,u[MX],cnt[MX],pnt[MX],z[MM],a[MM],b[MM],f[MM][MM];
int main() {
  scanf("%d%d",&m,&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=n; i<m; i++) a[i]=a[n-1];
  for (i=0; i<m; i++) {
    for (j=0; j<m; j++) f[i][j]=int(i!=j);
    b[i]=m-1;
  }
  memset(u,255,sizeof(u));
  for (i=0; i<m; i++) if (b[i]>a[i] || (i<n && b[i]!=a[i])) {
    for (j=i+1; j<m; j++) {
      cur=b[j]-a[j];
      if (j>=n) cur=max(0,cur);
      cur+=MD;
      if (u[cur]!=i) {
        u[cur]=i;
        cnt[cur]=1;
      } else cnt[cur]++;
    }
    for (j=0; j<MX-1; j++) pnt[j+1]=pnt[j]+(u[j]==i?cnt[j]:0);
    for (j=i+1; j<m; j++) {
      cur=b[j]-a[j];
      if (j>=n) cur=max(0,cur);
      z[pnt[cur+MD]++]=j;
    }
    mm=m-1-i;
    for (j=0; b[i]>a[i] && j<mm; j++) {
      f[i][z[j]]--;
      f[z[j]][i]++;
      b[i]--;
      b[z[j]]++;
    }
    for (j=mm-1; b[i]<a[i] && j>=0; j--) {
      f[i][z[j]]++;
      f[z[j]][i]--;
      b[i]++;
      b[z[j]]--;
    }
    if (b[i]>a[i] || (i<n && b[i]!=a[i])) {
      puts("no");
      return 0;
    }
  }
  puts("yes");
  for (i=0; i<m; i++,puts("")) for (j=0; j<m; j++) putchar(i==j?'X':ans[f[i][j]]);
  return 0;
}