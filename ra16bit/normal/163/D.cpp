#include <cmath>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
const long long inf=1000000000000LL;
int t,n,i,j,a[111],num,ri,rj;
long long m,x,cur,cz,mbi,res,p[111],b[4000000];
map <long long, pair <long long, long long> > M;
void rec(int l, long long cur) {
  if (l==n) {
    b[num++]=cur;
    return;
  }
  for (int i=0; i<=a[l]; i++) {
    rec(l+1,cur);
    cur*=p[l];
    if (cur>inf) break;
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    num=0; m=1;
    res=5000000000000000000LL;
    for (i=0; i<n; i++) {
      scanf("%I64d%d",&p[i],&a[i]);
      for (j=0; j<a[i]; j++) m*=p[i];
    }
    if (M.count(m)>0) {
      x=M[m].first;
      cur=M[m].second;
      res=m/x+m/cur+x*cur;
      printf("%I64d %I64d %I64d %I64d\n",2*res,m/x/cur,x,cur);
      continue;
    }
    rec(0,1);
    sort(b,b+num);
    //for (i=0; i<num; i++) printf("%d ",int(b[i])); puts("~");
    for (i=num-1; i>=0; i--) {
      x=(long long)sqrt(b[i]+1e-8);
      mbi=m/b[i];
      if (mbi*(x+x-1)+b[i]>=res) break;
      for (j=lower_bound(b,b+num,x)-b; j>=0; j--) {
        cz=mbi*(b[j]+b[i]/b[j])+b[i];
        //printf("%d %d %d %I64d\n",int(b[i]),int(b[j]),int(cz),(res));
        if (cz-mbi>res) break;
        if (b[i]%b[j]==0) {
          if (cz<res) { res=cz; ri=i; rj=j; }
          break;
        }
      }
    }
    printf("%I64d %I64d %I64d %I64d\n",2*res,m/b[ri],b[rj],b[ri]/b[rj]);
    M[m]=make_pair(m/b[ri],b[rj]);
  }
  return 0;
}