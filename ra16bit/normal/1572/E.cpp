#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,rlj,k,nxt,cur,len,res,x[444],y[444],mx[202][202];
long long le,ri,mid,s[202][202],f[202][202];
long long cross(long long xa, long long ya, long long xb, long long yb) {
  return abs(xa*yb-ya*xb);
}
long long cross(int i, int j, int k) {
  return cross(x[j]-x[i],y[j]-y[i],x[k]-x[i],y[k]-y[i]);
}
void tryupd(int i, int j, int v, long long s) {
  if (v>mx[i][j] || (v==mx[i][j] && s<f[i][j])) {
    mx[i][j]=v;
    f[i][j]=s;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    x[i+n]=x[i];
    y[i+n]=y[i];
  }
  for (i=0; i<n; i++) for (len=2; len<n; len++)
    s[i][len]=s[i][len-1]+cross(i,i+len-1,i+len);
  le=0; ri=s[0][len-1];
  while (le<ri) {
    mid=(le+ri)/2+1;
    res=0;
    for (len=2; len+1<n && res<m; len++) for (i=0; i<n; i++) {
      mx[i][len]=0;
      f[i][len]=0;
      j=i+len;
      rlj=j%n;
      if (s[i][len]>=mid && s[rlj][n-len]>=mid) {
        mx[i][len]=1;
        f[i][len]=s[i][len];
        tryupd(i,len,mx[i][len-1],f[i][len-1]);
        nxt=i+1;
        if (nxt>=n) nxt-=n;
        tryupd(i,len,mx[nxt][len-1],f[nxt][len-1]);
        cur=nxt+1;
        for (k=2; len-k>=2; k++, cur++) {
          if (cur>=n) cur-=n;
          tryupd(i,len,mx[i][k]+mx[cur][len-k],f[i][k]+f[cur][len-k]);
        }
        if (s[i][len]-f[i][len]>=mid) {
          ++mx[i][len];
          f[i][len]=s[i][len];
        }
        if (mx[i][len]>res) res=mx[i][len];
      }
    }
    if (res>=m) le=mid; else ri=mid-1;
  }
  printf("%lld\n",ri);
  return 0;
}