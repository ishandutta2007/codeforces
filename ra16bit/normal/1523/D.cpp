#include <bits/stdc++.h>
using namespace std;
const int B=64;
int n,m,num,p,i,j,k,cnt,res;
long long rmsk,good,msk[62],a[62][200200/B],cur[17][200200/B];
char s[77];
void rec(int l, int pos, int cntbits, long long nxt, long long cmsk) {
  if (l>=m) return;
  if (cntbits+__builtin_popcountll(nxt)<=res) return;
  ++cntbits;
  for (int j=pos; j<m; j++) if ((nxt>>j)&1) {
    long long nxtz=0;
    if (l==0) {
      for (int k=0; k<=num; k++) cur[l][k]=a[j][k];
      nxtz=(nxt&msk[j]);
    } else {
      int cnt=0;
      for (int k=0; k<=num; k++) {
        cur[l][k]=(cur[l-1][k]&a[j][k]);
        cnt+=__builtin_popcountll(cur[l][k]);
      }
      if (cnt*2>=n) {
        if (cntbits>res) {
          res=cntbits;
          rmsk=(cmsk|(1LL<<j));
        }
        nxtz=(nxt&msk[j]);
      }
    }
    if (nxtz>0) rec(l+1,j+1,cntbits,nxtz,cmsk|(1LL<<j));
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&p);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    for (j=0; j<m; j++) if (s[j]=='1') a[j][i/B]|=(1LL<<(i%B));
  }
  num=(n-1)/B;
  for (i=0; i<m; i++) {
    for (cnt=k=0; k<=num; k++) cnt+=__builtin_popcountll(a[i][k]);
    if (cnt*2>=n) { good|=(1LL<<i); res=1; rmsk=(1LL<<i); }
  }
  for (i=0; i<m; i++) if ((good>>i)&1) for (j=i+1; j<m; j++) if ((good>>j)&1) {
    for (cnt=k=0; k<=num; k++) cnt+=__builtin_popcountll(a[i][k]&a[j][k]);
    if (cnt*2>=n) { msk[i]|=(1LL<<j); res=2; rmsk=((1LL<<i)|(1LL<<j)); }
  }
  rec(0,0,0,good,0);
  for (i=0; i<m; i++) putchar('0'+char((rmsk>>i)&1));
  return 0;
}