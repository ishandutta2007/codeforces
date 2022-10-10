#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c,d;
long long x,y,z;
int gcd(int a, int b, long long &x, long long &y) {
  if (b==0) { x=1; y=0; return a; }
  int d;
  long long xx,yy;
  d=gcd(b,a%b,xx,yy);
  x=yy;
  y=xx-(a/b)*yy;
  return d;
}
int main() {
  cin>>a>>b>>c;
  d=gcd(a,b,x,y);
  if (c%d==0) {
    z=(-c)/d;
    cout<<x*z<<' '<<y*z<<'\n';
  } else puts("-1");
  return 0;
}