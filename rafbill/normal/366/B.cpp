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

int main(int, char**){
  long k, n; cin >> n >> k;
  vector<long> a(k);
  FOR(i, k) a[i] = 0;
  FOR(i, n){
    long b; cin >> b;
    a[i % k] += b;
  }
  long mi = 0;
  FOR(i, k){
    if(a[i] < a[mi]){
      mi = i;
    }
  }
  cout << mi+1 << endl;
  return 0;
}