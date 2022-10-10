#include <bits/stdc++.h>
using namespace std;
const int md=1000000007,MID=111*111;
int n,q,x,i,ii,i1,j,lst,len,lensum,cur,r,b[111],c[111];
long long f[2][MID];
map<int,int> was;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&c[i]);
  for (i=1; i<n; i++) scanf("%d",&b[i]);
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&x);
    if (x>c[1]) { puts("0"); continue; }
    //x=max(x,-102);
    auto it=was.find(x);
    if (it!=was.end()) { printf("%d\n",it->second); continue; }
    r=cur=len=lensum=0;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for (i=1; i<=n; i++) {
      ii=i&1; i1=1-ii;
      cur+=c[i];
      for (j=0; j<=cur; j++) for (f[ii][j]=lst=0; lst<=j && lst<=c[i]; lst++) if (f[i1][j-lst]) {
        if (x*i+lensum<=j) f[ii][j]=(f[ii][j]+f[i1][j-lst])%md;
      }
      len+=b[i];
      lensum+=len;
    }
    for (j=0; j<=cur; j++) r=(r+f[n&1][j])%md;
    printf("%d\n",r);
    was[x]=r;
  }
  return 0;
}