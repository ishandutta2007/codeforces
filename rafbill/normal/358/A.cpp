#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <bitset>
#include <iostream>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORD(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

int main(int, char**){
  long n; cin >> n;
  vector<long> v(n);
  FOR(i, n){
    cin >> v[i];
  }
  bool ok = true;
  FOR(i, n-1){
    FORU(j, i+1, n-2){
      long a = v[i], b = v[i+1];
      if(a > b) swap(a, b);
      long c = v[j], d = v[j+1];
      if(c > d) swap(c, d);
      if((a < c && b > c && b < d) || (a > c && a < d && b > d)){
        ok = false;
        break;
      }
    }
  }
  cout << (ok ? "no" : "yes") << endl;
  return 0;
}