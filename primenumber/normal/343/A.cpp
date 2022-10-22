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

int64_t search(int64_t a,int64_t b) {
  if(a == 0)
    return 0;
  else if(a >= b)
    return search(a%b,b) + a/b;
  else if((b % a) == 0)
    return b/a;
  else
    return search(a,b%a) + b/a;
}

int main() {
  int64_t a,b;
  cin >> a >> b;
  cout << search(a,b) << endl;
  return 0;
}