#include <bits/stdc++.h>
using namespace std;
const long long MX=1000100LL;
int n,i,j,lj,rj,e,best,med;
bool a[MX];
long long cur,lv,v[200200],b[400200];
void check(long long i) {
  for (int j=cur=0; j<n; j++) {
    long long z=v[j]%i;
    if ((cur+=(v[j]<i?i-z:min(z,i-z)))>=best) break;
  }
  if (cur<best) best=cur;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d",&v[i]);
    best+=(v[i]&1);
  }
  med=v[0]-max(v[0]-best,MX);
  lj=max(0,med-best);
  rj=med+best;
  for (j=lj; j<=rj; j++) b[j]=v[0]+j-med;
  for (i=2; i<MX; i++) if (!a[i]) {
    for (j=i+i; j<MX; j+=i) a[j]=true;
    lj=max(0,med-best);
    rj=med+best;
    if (lj<=rj) {
      lv=v[0]+lj-med;
      e=lv%i;
      if (e) e=i-e;
      for (j=lj+e; j<=rj; j+=i) while (b[j]%i==0) b[j]/=i;
    }
    if (i>2) check(i);
  }
  lj=max(0,med-best);
  rj=med+best;
  for (j=lj; j<=rj; j++) if (b[j]>=MX) check(b[j]);
  printf("%d\n",best);
  return 0;
}