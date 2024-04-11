#include <bits/stdc++.h>
using namespace std;
const int MX=5005,md=1000000007;
int n,m,i,y,sum,res,lft[MX],rgh[MX],le[MX],ri[MX],a[MX],c[MX];
long long cur,cnt,cz;
vector<int> v[MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void add(int i) {
  int mx=max(lft[i],rgh[i]);
  int mn=min(lft[i],rgh[i]);
  if (mn>0) {
    ++sum;
    cur=(cur*mn)%md;
    if (mx>1) {
      ++sum;
      cur=(cur*(mx-1LL))%md;
    } else cur=(cur*2LL)%md;
  } else if (mx>0) {
    ++sum;
    cur=(cur*mx)%md;
  }
}
void rm(int i) {
  int mx=max(lft[i],rgh[i]);
  int mn=min(lft[i],rgh[i]);
  if (mn>0) {
    --sum;
    cur=(cur*pw(mn,md-2))%md;
    if (mx>1) {
      --sum;
      cur=(cur*pw(mx-1,md-2))%md;
    } else cur=(cur*pw(2,md-2))%md;
  } else if (mx>0) {
    --sum;
    cur=(cur*pw(mx,md-2))%md;
  }
}
long long rmfake(int i) {
  int mx=max(lft[i],rgh[i]);
  int mn=min(lft[i],rgh[i]);
  long long cz=cur;
  if (mn>0) {
    cz=(cz*pw(mn,md-2))%md;
    if (mx>1) cz=(cz*pw(mx-1,md-2))%md; else cz=(cz*pw(2,md-2))%md;
  } else if (mx>0) {
    cz=(cz*pw(mx,md-2))%md;
  }
  return cz;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    v[a[i]].push_back(i);
  }
  for (i=1; i<=m; i++) {
    scanf("%d%d",&c[i],&y);
    if (v[c[i]].size()<y) continue;
    le[v[c[i]][y-1]]=i;
    ri[v[c[i]][int(v[c[i]].size())-y]]=i;
    if (++rgh[c[i]]==1) ++sum;
  }
  for (cur=i=1; i<=n; i++) if (rgh[i]) cur=(cur*rgh[i])%md;
  res=sum;
  cnt=cur;
  for (i=1; i<=n; i++) {
    if (ri[i]) {
      rm(a[i]);
      --rgh[a[i]];
      add(a[i]);
    }
    if (le[i]) {
      rm(a[i]);
      ++lft[a[i]];
      add(a[i]);
      if (sum>res) { res=sum; cnt=0; }
      if (sum==res) {
        cz=rmfake(a[i]);
        if (rgh[a[i]]>0) {
          cz=(cz*(rgh[a[i]]-int(rgh[a[i]]>lft[a[i]] || (rgh[a[i]]==lft[a[i]] && rgh[a[i]]>1))))%md;
        }
        cnt=(cnt+cz)%md;
      }
    }
  }
  printf("%d %d\n",res,int(cnt));
  return 0;
}