#include <bits/stdc++.h>
using namespace std;
const int md=1000000007,MID=111*111,ST=100000;
int n,q,x,le,ri,i,ii,i1,j,lst,len,lensum,cur,r,b[111],c[111];
long long f[2][MID];
map<int,int> a;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&c[i]);
  for (i=1; i<n; i++) scanf("%d",&b[i]);
  f[0][0]=1;
  for (i=1; i<=n; i++) {
    ii=i&1; i1=1-ii;
    cur+=c[i];
    a[100000]=-1;
    for (j=0; j<=cur; j++) {
      le=0; ri=2*ST;
      while (le<ri) {
        x=(le+ri)/2+1;
        if ((x-ST)*i+lensum<=j) le=x; else ri=x-1;
      }
      a[ri-ST]=-1;
      f[ii][j]=(f[ii][j]+f[i1][j-lst])%md;
    }
    len+=b[i];
    lensum+=len;
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&x);
    if (x>c[1]) { puts("0"); continue; }
    auto it=a.lower_bound(x);
    if (it->second>=0) { printf("%d\n",it->second); continue; }
    x=it->first;
    r=cur=len=lensum=0;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for (i=1; i<=n; i++) {
      ii=i&1; i1=1-ii;
      cur+=c[i];
      for (j=1; j<=cur; j++) if ((f[i1][j]+=f[i1][j-1])>=md) f[i1][j]-=md;
      le=x*i+lensum;
      if (le>=MID) break;
      for (j=0; j<le; j++) f[ii][j]=0;
      for (; j<=cur; j++) {
        f[ii][j]=f[i1][j];
        if (j>c[i] && (f[ii][j]-=f[i1][j-c[i]-1])<0) f[ii][j]+=md;
      }
      len+=b[i];
      lensum+=len;
    }
    if (i>n) for (j=0; j<=cur; j++) r=(r+f[n&1][j])%md;
    printf("%d\n",r);
    a[x]=r;
  }
  return 0;
}