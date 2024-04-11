#include <bits/stdc++.h>
using namespace std;
const int MX=2021;
const long long inf=2000000000000000000LL;
int t,n,m,i,j;
long long le,ri,h,v,cur,cz,cnt,c[MX][MX];
int main() {
  for (i=0; i<MX; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=min(inf,c[i-1][j]+c[i-1][j-1]);
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    if (n==1) { puts("0"); continue; }
    le=1; ri=n;
    while (le<ri) {
      h=(le+ri)/2;
      cur=h*m;
      cnt=1;
      for (i=1; i<=h && i<=cur && cur>0 && cnt<n; i++) {
        if (i==1) v=h; else if (i==2) v=(h*(h-1LL))/2; else
          if (i==3) v=(h*(h-1LL)*(h-2LL))/6; else {
            assert(h<MX);
            v=c[h][i];
          }
        v=min(v,cur/i);
        cnt+=v;
        cur-=v*i;
      }
      if (cnt>=n) ri=h; else le=h+1;
    }
    printf("%d\n",int(ri));
  }
  return 0;
}