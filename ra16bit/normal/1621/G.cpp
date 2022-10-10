#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=1000000007;
int t,n,i,j,pos,prv,ans,a[MX],s[MX],lft[MX];
pair<int,int> b[MX];
long long res[MX],cur;
void add(int i, int v) {
  for (; i<=n; i=(i<<1)-(i&(i-1))) if ((s[i]+=v)>=md) s[i]-=md;
}
int sum(int i) {
  int r=0;
  for (; i>0; i&=i-1) if ((r+=s[i])>=md) r-=md;
  return r;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (ans=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      b[i].first=a[i];
      b[i].second=-i;
    }
    sort(b,b+n);
    for (i=0; i<n; i++) a[-b[i].second]=i+1;
    for (i=1; i<=n; i++) s[i]=0;
    for (i=0; i<n; i++) {
      lft[i]=(sum(a[i]-1)+1)%md;
      add(a[i],lft[i]);
    }
    for (i=1; i<=n; i++) s[i]=0;
    for (i=n-1; i>=0; i--) {
      cur=(sum(n)+md+1-sum(a[i]))%md;
      add(a[i],cur);
      ans=(ans+lft[i]*cur)%md;
    }
    for (i=1; i<=n; i++) s[i]=0;
    prv=0;
    for (i=n-1; i>=0; i--) if (a[i]>prv) {
      for (j=a[i]; j>prv; j--) {
        pos=-b[j-1].second+1;
        res[pos]=(j==a[i])?1:(sum(n)+md-sum(pos))%md;
        ans=(ans+md-(lft[pos-1]*res[pos])%md)%md;
        add(pos,res[pos]);
      }
      for (j=a[i]; j>prv; j--) {
        pos=-b[j-1].second+1;
        add(pos,(md-res[pos])%md);
      }
      prv=a[i];
    }
    printf("%d\n",ans);
  }
  return 0;
}