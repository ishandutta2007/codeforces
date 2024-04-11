#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=998244353;
int t,n,i,res,a[MX];
long long s[MX],cur,tot;
int solve(long long st, int lft, int rgh) {
  if (st>tot || lft>rgh) return 0;
  int le=0,ri=(rgh-lft)/2;
  while (le<ri) {
    int h=(le+ri)/2+1;
    int pos=lft+h*2;
    long long cur=st+s[pos]-s[lft];
    if (cur>tot) ri=h-1; else le=h;
  }
  return ri+1;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    cur=tot=0;
    for (res=i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      tot+=a[i];
      if (i<=2) s[i]=a[i]; else s[i]=s[i-2]+a[i];
    }
    tot=(tot-1)/2;
    for (i=n; i>0; i--) {
      cur+=a[i];
      if (cur<=tot) ++res; else break;
    }
    for (i=1; i<n; i++) {
      cur=s[i]+s[i-1];
      res=(res+solve(cur,i,n))%md;
      res=(res+solve(cur+a[n],i,n-3))%md;
      if (i>1) {
        cur-=a[1];
        res=(res+solve(cur,i,n))%md;
        res=(res+solve(cur+a[n],i,n-3))%md;
      }
    }
    printf("%d\n",res);
  }
  return 0;
}