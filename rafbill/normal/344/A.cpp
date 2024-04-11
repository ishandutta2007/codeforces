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

int main(int, char**){
  long n; cin >> n;
  long r = 1;
  long l; cin >> l;
  bool b = l == 1;
  FOR(i, n-1){
    cin >> l;
    r += b != (l == 1);
    b = (l == 1);
  }
  cout << r << endl;
  return 0;
}