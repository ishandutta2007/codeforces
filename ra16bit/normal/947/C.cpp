#include <bits/stdc++.h>
using namespace std;
const int MX=300300*31;
int n,i,j,k,cur,num,a[300300],x[300300],b[MX][2],cnt[MX],o[MX],p[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) {
    scanf("%d",&x[i]);
    for (k=0, j=30; j>=0; j--) {
      cur=((x[i]>>j)&1);
      if (b[k][cur]==0) {
        b[k][cur]=++num;
        p[num]=k;
      }
      k=b[k][cur];
      cnt[k]++;
    }
    o[k]=i;
  }
  for (i=0; i<n; i++) {
    for (k=0, j=30; j>=0; j--) {
      cur=((a[i]>>j)&1);
      if (b[k][cur]>0 && cnt[b[k][cur]]>0) k=b[k][cur]; else k=b[k][cur^1];
    }
    printf("%d ",a[i]^x[o[k]]);
    for (; k>0; k=p[k]) cnt[k]--;
  }
  return 0;
}