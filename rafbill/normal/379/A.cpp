#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>

using namespace std;

#define FOR(i, n) for(unsigned i = 0; i < (n); ++i)
#define FORU(i, j, k) for(unsigned i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(unsigned i = (j); i >= (k); --i)

int main(int, char**){
  long a, b, c; cin >> a >> b;
  long r = 0;
  c = 0;
  while(a != 0){
    r += a;
    a += c;
    c = a % b;
    a /= b;
  }
  cout << r << endl;
  return 0;
}