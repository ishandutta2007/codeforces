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
  char c;long h1; long m1; long h2; long m2;
  cin >> h1 >> c >> m1 >> h2 >> c >> m2;
  long h3 = h1-h2;
  long m3 = m1-m2;
  while(m3 < 0){
    m3 += 60; h3 -= 1;
  }
  while(m3 >= 60){
    m3 -= 60; h3 += 1;
  }
  while(h3 < 0){ h3 += 24; }
  while(h3 >= 24){ h3 -= 24; }
  cout << (h3 < 10 ? "0" : "") << h3 << ":" << (m3 < 10 ? "0" : "") << m3 << endl;
  return 0;
}