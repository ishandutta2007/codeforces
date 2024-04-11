#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

LL F(LL x) {
  if (x<10) return x;
  LL ans=9;
  unsigned long long t=100, p=1;
  for (;t<=x;) {
    ans+=p*9;
    t*=10;
    p*=10;
  }
  t/=10;
  LL o=x/t, e=x%t;
  ans+=p*(o-1);
  ans+=e/10;
  if (o<=e%10) ans++;
  return ans;
}

int main(){
  LL l, r;
  cin>>l>>r;
  cout<<F(r)-F(l-1)<<endl;
  return 0;
}