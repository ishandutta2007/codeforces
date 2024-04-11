#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long s;
  int cnt;
} a[1100100];
int n,i,x,cur,nxt;
long long sum,up,tot;
void mdf(int i, int L, int R) {
  if (L>=cur && R<nxt) {
    a[i].s+=cur;
    tot+=1LL*cur*a[i].cnt;
    if (R+1==nxt) { cur+=x; nxt+=x; }
    return;
  }
  int h=(L+R)/2;
  if (cur<=h) mdf(i*2,L,h);
  mdf(i*2+1,h+1,R);
}
void setactive(int i, int L, int R) {
  up+=a[i].s;
  ++a[i].cnt;
  if (L==R) {
    tot+=up;
    return;
  }
  int h=(L+R)/2;
  if (x<=h) setactive(i*2,L,h); else setactive(i*2+1,h+1,R);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
    cur=x; nxt=x+x;
    mdf(1,1,300000);
    up=0;
    setactive(1,1,300000);
    sum+=x;
    printf("%lld ",sum*i-tot);
  }
  return 0;
}