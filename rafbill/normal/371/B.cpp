#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <bitset>
#include <set>
#include <functional>
#include <tuple>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, a, b) for(long i = a; i <= (b); ++i)
#define FORR(i, a, b) for(long i = a; i >= (b); --i)

using namespace std;

long gcd(long a, long b){
  if(a % b == 0){
    return b;
  }else{
    return gcd(b, a % b);
  }
}

long f(long a, long g){
  long d = a / g;
  long n = 0;
  while(d % 2 == 0){
    d /= 2;
    n += 1;
  }
  while(d % 3 == 0){
    d /= 3;
    n += 1;
  }
  while(d % 5 == 0){
    d /= 5;
    n += 1;
  }
  if(d == 1) return n;
  else return -1;
}

int main(int, char**){
  long a, b; cin >> a >> b;
  long g = gcd(a, b);
  long r1 = f(a, g), r2 = f(b, g);
  if(r1 == -1 || r2 == -1) cout << -1 << endl;
  else cout << r1+r2 << endl;
  return 0;
}