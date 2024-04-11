#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int gcd(int x, int y) {
  if(x < y)
    return gcd(y,x);
  else if(y == 0)
    return x;
  else
    return gcd(y,x%y);
}

int main() {
  int n;
  cin>>n;
  vecint a(n);
  REP(i,n) cin>>a[i];
  int gcda = a[0];
  FOR(i,1,n) gcda = gcd(gcda,a[i]);
  int m = a[0];
  FOR(i,1,n) m = max(m,a[i]);
  int count = (m/gcda) - n;
  if(count % 2)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}