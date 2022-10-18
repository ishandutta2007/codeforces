#include <cstdio>
#include <iostream>
using namespace std;

int k,l,m,n; int d;
int res = 0;

int f(int x) { return d / x; }
int gcd(int a,int b) { return (b==0)?a:gcd(b,a%b); }
int lcm(int a,int b) { return (a*b)/gcd(a,b); }

int main() {
  cin >> k >> l >> m >> n;
  cin >> d;
  
  cout <<
  f(k) + f(l) + f(n) + f(m) 
  - ( f(lcm(k,l)) + f(lcm(k,n)) + f(lcm(k,m)) + f(lcm(l,n)) + f(lcm(l,m)) + f(lcm(n,m)) ) 
  + f(lcm(lcm(k,l),n)) + f(lcm(lcm(k,l),m)) + f(lcm(lcm(k,n),m)) + f(lcm(lcm(l,n),m))
  - f(lcm(lcm(k,l),lcm(n,m))) << endl;
  return 0;
}