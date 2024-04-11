#include <bits/stdc++.h>
using namespace std;
long long n;
unsigned long long x,r;
char c;
int main() {
  scanf("%I64d%c",&n,&c);
  n--; x=n/4; n%=4;
  r=x*16+(n%2)*7;
  if (c<='c') r+=4+c-'a'; else r+='g'-c;
  cout<<r<<'\n';
  return 0;
}