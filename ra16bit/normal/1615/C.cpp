#include <bits/stdc++.h>
using namespace std;
const int inf=1000000000;
int t,n,i,j,x,cnt[2][2],snt[2][2],dst[2],res;
char a[100100],b[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    res=inf;
    for (i=0; i<2; i++) for (j=0; j<2; j++) {
      cnt[i][j]=0;
      snt[i][j]=0;
    }
    dst[0]=dst[1]=0;
    for (i=0; i<n; i++) {
      ++cnt[b[i]-'0'][a[i]-'0'];
      ++snt[b[i]-'0'][a[i]-'0'];
      ++dst[b[i]-'0'];
    }
    for (x=0; x<2; x++) {
      for (i=0; i<2; i++) for (j=0; j<2; j++) cnt[i][j]=snt[i][j];
      for (i=0; ; i++) {
        if (cnt[0][0]==dst[0] && cnt[1][1]==dst[1]) break;
        j=((i+x)&1);
        if (cnt[j][1]==0) break;
        --cnt[j][1];
        swap(cnt[0][0],cnt[0][1]);
        swap(cnt[1][0],cnt[1][1]);
        ++cnt[j][1];
      }
      if (cnt[0][0]==dst[0] && cnt[1][1]==dst[1]) res=min(res,i);
    }
    printf("%d\n",(res==inf)?-1:res);
  }
  return 0;
}