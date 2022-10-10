#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,m,i,j,cur,pos,lftup,rghup,a[MX],num[MX],w[MX],cnt[MX];
long long sum[MX];
vector<int> v[MX],eq;
int fnd(long long sum, long long num) {
  int le=0,ri=n;
  while (le<ri) {
    int mid=(le+ri)/2;
    if (sum>a[mid]*num) ri=mid; else le=mid+1;
  }
  return ri;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    for (a[n]=i=0; i<=n; i++) cnt[i]=0;
    for (i=0; i<m; i++) {
      scanf("%d",&num[i]);
      v[i].resize(num[i]);
      for (sum[i]=j=0; j<num[i]; j++) {
        scanf("%d",&v[i][j]);
        sum[i]+=v[i][j];
      }
      w[i]=fnd(sum[i],num[i]);
      ++cnt[w[i]];
    }
    for (i=1; i<=n; i++) cnt[i]+=cnt[i-1];
    lftup=-1;
    eq.clear();
    for (i=0; i<=n; i++) if (cnt[i]>i) {
      if (cnt[i]>i+1) break;
      if (lftup==-1) lftup=i;
      rghup=i;
    } else if (cnt[i]==i) eq.push_back(i);
    if (i<=n) {
      for (i=0; i<m; i++) for (j=0; j<num[i]; j++) putchar('0');
    } else for (i=0; i<m; i++) for (j=0; j<num[i]; j++) {
      cur=fnd(sum[i]-v[i][j],num[i]-1);
      if (lftup==-1) {
        if (cur<w[i]) {
          pos=lower_bound(eq.begin(),eq.end(),cur)-eq.begin();
          printf("%d",int(pos>=eq.size() || eq[pos]>=w[i]));
        } else putchar('1');
      } else printf("%d",int(w[i]<=lftup && cur>rghup));
    }
    putchar('\n');
  }
  return 0;
}