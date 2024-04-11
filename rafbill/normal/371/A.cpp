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

long A[100];

int main(int, char**){
  long n, k; cin >> n >> k;
  FOR(i, n) cin >> A[i];
  long ans = 0;
  FOR(i, k){
    long r = 0;
    FOR(j, n/k){
      r += A[i+j*k] == 1;
    }
    ans += min(r, n/k - r);
  }
  cout << ans << endl;
  return 0;
}