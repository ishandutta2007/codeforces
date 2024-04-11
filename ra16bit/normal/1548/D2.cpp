#include <bits/stdc++.h>
using namespace std;
int n,i,j,jx,jy,jz,kx,ky,kz,b,s,x[6006],y[6006],cnt[4][4][4],g[6006][6006];
long long cur,r,rc[4];
int gcd(int a, int b) {
  return b?gcd(b,a%b):a;
}
int cross(int xa, int ya, int xb, int yb) {
  return xa*yb-ya*xb;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    for (j=0; j<i; j++) g[i][j]=g[j][i]=gcd(abs(x[i]-x[j]),abs(y[i]-y[j]));
  }
  for (i=0; i<n; i++) {
    memset(cnt,0,sizeof(cnt));
    for (j=0; j<n; j++) if (i!=j) ++cnt[x[j]%4][y[j]%4][g[i][j]%4];
    for (jx=0; jx<4; jx++) for (jy=0; jy<4; jy++) for (kx=0; kx<4; kx++) for (ky=0; ky<4; ky++) {
      b=gcd(abs(jx-kx),abs(jy-ky));
      if (b&1) continue;
      s=abs(cross(jx-x[i]%4,jy-y[i]%4,kx-x[i]%4,ky-y[i]%4));
      if (s&1) continue;
      for (jz=0; jz<4; jz++) if (cnt[jx][jy][jz]) {
        cur=cnt[jx][jy][jz]--;
        for (kz=0; kz<4; kz++) if (cnt[kx][ky][kz] && (jz+kz+b)%4==s%4) rc[3-int(jz&1)-int(kz&1)]+=cur*cnt[kx][ky][kz];
        ++cnt[jx][jy][jz];
      }
    }
  }
  for (i=1; i<=3; i++) r+=rc[i]/i;
  printf("%lld\n",r/2);
  return 0;
}