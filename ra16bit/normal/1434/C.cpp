#include <bits/stdc++.h>
using namespace std;
int t,A,B,C,D;
long long a,b,c,d,e,o,lst,cnt;
long long sum(long long x) {
  return (x*(x+1LL))/2;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d%d",&A,&B,&C,&D);
    a=A; b=B;
    c=C; d=D;
    e=c/d;
    o=c%d;
    lst=a-b*(o+d*e);
    if (lst>0) { puts("-1"); continue; }
    cnt=a/(d*b);
    printf("%lld\n",(cnt+1LL)*a-sum(cnt)*d*b);
  }
  return 0;
}