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
  long r1, r2, r3;
  cin >> r1 >> r2 >> r3;
  long aa = r1+r2-r3;
  long bb = r2+r3-r1;
  long cc = r1+r3-r2;
  if((aa % 2 + bb % 2 + cc % 2 == 0) && aa >= 0 && bb >= 0 && cc >= 0 && (aa+bb > 0) && (aa+cc > 0) && (bb+cc > 0)){
    cout << aa/2 << " " << bb/2 << " " << cc/2 << endl;
  }else{
    cout << "Impossible" << endl;
  }
  return 0;
}