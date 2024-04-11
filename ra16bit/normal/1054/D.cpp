#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,y,a[200200];
map<int,int> c;
long long r;
int main() {
  scanf("%d%d",&n,&m);
  r=(n*(n+1LL))/2;
  m=(1<<m)-1;
  c[0]++;
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    a[i]^=a[i-1];
    if (c[a[i]^m]<c[a[i]]) a[i]^=m;
    r-=c[a[i]];
    c[a[i]]++;
  }
  printf("%I64d\n",r);
  return 0;
}