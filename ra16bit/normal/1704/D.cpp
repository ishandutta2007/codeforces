#include <bits/stdc++.h>
using namespace std;
const int MX=300100;
int t,n,m,i,j,k,w,cnt;
long long pos,neg,d,res;
vector<long long> a[MX],b[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&m,&n);
    for (i=0; i<m; i++) {
      a[i].resize(n);
      for (j=0; j<n; j++) scanf("%lld",&a[i][j]);
      b[i]=a[i];
    }
    for (i=0; i<2; i++) {
      for (j=0; j<m; j++) b[j]=a[j];
      for (cnt=k=0; k<m; k++) if (i!=k) {
        for (pos=neg=j=0; j+1<n; j++) {
          d=b[k][j]-b[i][j];
          b[k][j]-=d;
          b[k][j+1]+=d;
          if (d<0) neg-=d; else pos+=d;
        }
        for (; j<n; j++) if (b[k][j]!=b[i][j]) break;
        if (j<n || pos!=neg) {
          w=k+1;
          ++cnt;
          res=abs(pos-neg);
        }
      }
      if (cnt==1) {
        printf("%d %lld\n",w,res);
        break;
      }
    }
  }
  return 0;
}