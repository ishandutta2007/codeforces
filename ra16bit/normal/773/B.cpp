#include <bits/stdc++.h>
using namespace std;
const int Q[6]={32,16,8,4,2,1};
const int score[6]={12,10,8,6,4,2};
const int inf=7000;
int n,i,j,le,ri,h,a[122][7],cnt[7],cur,x,y;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<5; j++) {
    scanf("%d",&a[i][j]);
    if (a[i][j]>=0) {
      a[i][j]=250-a[i][j];
      ++cnt[j];
    }
  }
  for (ri=0; ri<=n*32; ri++) {
    for (x=y=i=0; i<5; i++) {
      cur=(a[0][i]==-1 || a[1][i]==-1 || a[0][i]>a[1][i])?cnt[i]:(cnt[i]+ri);
      for (j=0; j<6; j++) if (cur*Q[j]<=n+ri) break;
      if (a[0][i]!=-1) x+=score[j]*a[0][i];
      if (a[1][i]!=-1) y+=score[j]*a[1][i];
    }
    if (x>y) break;
  }
  printf("%d\n",(ri>n*32)?-1:ri);
  return 0;
}