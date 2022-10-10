#include <bits/stdc++.h>
using namespace std;
const int MX=200200,SZ=477;
int n,m,i,j,k,z,op,len,cur,cnt,x[MX][2],st[MX],c[MX],ptr[SZ],a[SZ+5][SZ+5];
bool small[MX];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    for (j=0; j<2; j++) scanf("%d",&x[i][j]);
    small[i]=(x[i][0]+x[i][1]<SZ);
  }
  for (i=1; i<=m; i++) {
    scanf("%d%d",&op,&cur);
    cnt+=c[i];
    for (j=2; j<SZ; j++) {
      if (++ptr[j]>=j) ptr[j]=0;
      cnt+=a[j][ptr[j]];
    }
    len=x[cur][0]+x[cur][1];
    if (op==2) if ((i-st[cur])%len>=x[cur][0]) --cnt;
    if (small[cur]) {
      if (op==1) {
        st[cur]=i;
        --a[len][i%len];
        ++a[len][(i+x[cur][0])%len];
      } else {
        ++a[len][st[cur]%len];
        --a[len][(st[cur]+x[cur][0])%len];
      }
    } else if (op==1) {
      st[cur]=i;
      for (j=i+x[cur][0], k=z=1; j<=m; z=-z) {
        c[j]+=z;
        j+=x[cur][k];
        k^=1;
      }
    } else {
      for (j=st[cur]+x[cur][0], k=z=1; j<=m; z=-z) {
        c[j]-=z;
        j+=x[cur][k];
        k^=1;
      }
    }
    /*for (j=2; j<5; j++) {
    for (k=0; k<j; k++) printf("%d, ",a[j][k]);printf(" --> %d\n",j);
    }*/
    printf("%d\n",cnt);
  }
  return 0;
}