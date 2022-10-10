#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=200200;
int t,n,m,num,i,ii,j,x,st,a[MX],le[MX],ri[MX],k[MX*2],all[MX];
long long f[MX][2],lft,rgh,cur,res;
set<pii> o;
bool cmp(int i, int j) {
  int pi=(i<0)?ri[-i]:le[i];
  int pj=(j<0)?ri[-j]:le[j];
  if (pi!=pj) return (pi<pj);
  if ((i>0)!=(j>0)) return (i>0);
  if (i<0) return le[-i]>le[-j];
  return false;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    num=0;
    for (i=1; i<=m; i++) {
      scanf("%d%d",&le[i],&ri[i]);
      j=lower_bound(a,a+n,le[i])-a;
      if (j>=n || a[j]>ri[i]) {
        k[num++]=i;
        k[num++]=-i;
      }
    }
    if (num==0) { puts("0"); continue; }
    sort(k,k+num,cmp);
    for (ii=m=0; ii<num; ii++) {
      i=k[ii];
      if (i<0) {
        i=-i;
        auto it=o.find({le[i],i});
        if (it==o.end()) continue;
        all[m++]=i;
        while (!o.empty()) {
          it=o.begin();
          if (it->first<=le[i]) o.erase(it); else break;
        }
      } else o.insert({le[i],i});
    }
    if (m==0) { puts("0"); continue; }
    //printf("%d\n",m);
    //for (i=0; i<m; i++) printf("[%d %d]\n",le[all[i]],ri[all[i]]);
    for (i=j=0; i<n; i++) {
      for (st=j; j<m && ri[all[j]]<=a[i]; j++);
      if (st==j) {
        f[i][0]=f[i][1]=(i>0?f[i-1][0]:0);
        continue;
      }
      if (i==0) {
        f[i][0]=a[i]-ri[all[st]];
        f[i][1]=f[i][0]*2;
        continue;
      }
      lft=le[all[j-1]]-a[i-1];
      f[i][0]=f[i][1]=min(f[i-1][0]+lft*2LL,f[i-1][1]+lft);
      rgh=a[i]-ri[all[st]];
      f[i][0]=min(f[i][0],f[i-1][0]+rgh);
      f[i][1]=min(f[i][1],f[i-1][0]+rgh*2LL);
      for (x=st+1; x<j; x++) {
        lft=le[all[x-1]]-a[i-1];
        rgh=a[i]-ri[all[x]];
        cur=min(f[i-1][0]+lft*2LL,f[i-1][1]+lft);
        f[i][0]=min(f[i][0],cur+rgh);
        f[i][1]=min(f[i][1],cur+rgh*2LL);
      }
      f[i][0]=min(f[i][0],f[i][1]);
    }
    if (j<m) {
      lft=le[all[m-1]]-a[n-1];
      res=min(f[n-1][0]+lft*2LL,f[n-1][1]+lft);
    } else res=f[n-1][0];
    printf("%lld\n",res);
  }
  return 0;
}