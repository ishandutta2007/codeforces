#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <list>
#include <bitset>

using namespace std;

using LL = long long int;

#define FOR(i, n) for(LL i = 0; i < n; ++i)
#define FORU(i, a, b) for(LL i = a; i <= b; ++i)
#define FORD(i, b, a) for(LL i = b; i >= a; --i)

LL gcd(LL a, LL b){
  LL r = a % b;
  return r == 0 ? b : gcd(b, r);
}

LL f(LL a, LL b){
  if(a < b){
    return f(b, a);
  }else if(b == 1){
    return a;
  }else{
    return (a / b) + f(b, a - b * (a / b));
  }
}

int main(int, char**){
  LL a, b;
  cin >> a >> b;
  cout << f(a, b) << endl;
  return 0;
}