#include <bits/stdc++.h>
using namespace std;
const int MX=200200,inf=1000100100;
int n,m,k,i,j,x,y,l,r,h,le,ri,mid,dst[2][MX],q[MX],a[MX],z[MX],mxy[19][MX];
vector<int> g[MX];
void bfs(int st) {
  int fi=0,fr=1;
  for (int i=0; i<n; i++) dst[st][i]=int(i!=st)*inf;
  q[0]=st;
  while (fi<fr) {
    int x=q[fi++];
    for (int y: g[x]) if (dst[st][y]==inf) {
      dst[st][y]=dst[st][x]+1;
      q[fr++]=y;
    }
  }
}
bool cmp(int i, int j) {
  return dst[0][i]<dst[0][j];
}
int findmax(int le, int ri) {
  int j=z[ri-le];
  return max(mxy[j][le],mxy[j][ri-(1<<j)]);
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  z[0]=0;
  for (i=0; i<k; i++) {
    scanf("%d",&a[i]);
    a[i]%=n;
    z[i+1]=z[i];
    if (i+1==(1<<(z[i+1]+1))) ++z[i+1];
  }
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    x%=n;
    y%=n;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bfs(0);
  bfs(1);
  sort(a,a+k,cmp);
  for (i=0; i<k; i++) mxy[0][i]=dst[1][a[i]];
  for (j=1; j<19; j++) {
    x=(1<<(j-1));
    for (i=0; i<k; i++) {
      mxy[j][i]=mxy[j-1][i];
      if (i+x<k) mxy[j][i]=max(mxy[j][i],mxy[j-1][i+x]);
    }
  }
  l=1; r=dst[0][1];
  //printf("r=%d\n",r);
  //for (i=0; i<k; i++) printf("[%d %d %d] ",a[i],dst[0][a[i]],dst[1][a[i]]); puts("");
  while (l<r) {
    h=(l+r)/2+1;
    //printf("check %d\n",h);
    for (i=0; i<k; i++) {
      le=0;
      ri=k-1;
      x=h-1-dst[1][a[i]];
      if (dst[0][a[ri]]<x) continue;
      //printf("  i=%d x=%d\n",i,x);
      while (le<ri) {
        mid=(le+ri)/2;
        if (dst[0][a[mid]]>=x) ri=mid; else le=mid+1;
      }
      //printf("  %d : %d\n",i,ri);
      if (ri<i && findmax(ri,i)>=h-1-dst[0][a[i]]) break;
      if (i+1<k) {
        ri=max(ri,i+1);
        if (ri<k && findmax(ri,k)>=h-1-dst[0][a[i]]) break;
      }
    }
    if (i<k) l=h; else r=h-1;
  }
  printf("%d\n",r);
  return 0;
}