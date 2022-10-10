#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
typedef pair<long long,int> pli;
int n,m,i,a[MX],b[MX];
long long c[MX],nxt[MX],res;
priority_queue<pli> q;
long long sqr(long long x) {
  return x*x;
}
long long calc(long long x, int k) {
  long long d=x/k,o=x%k;
  return (k-o)*sqr(d)+o*sqr(d+1);
}
int main() {
  scanf("%d%d",&n,&m);
  m-=n;
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    b[i]=1;
    c[i]=calc(a[i],1);
    res+=c[i];
    if (a[i]>1) {
      nxt[i]=calc(a[i],2);
      q.push({c[i]-nxt[i],i});
    }
  }
  while (m--) {
    res-=q.top().first;
    i=q.top().second;
    q.pop();
    ++b[i];
    c[i]=nxt[i];
    if (a[i]>b[i]) {
      nxt[i]=calc(a[i],b[i]+1);
      q.push({c[i]-nxt[i],i});
    }
  }
  printf("%I64d\n",res);
  return 0;
}