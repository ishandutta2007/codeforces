#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

#define FOR(i, n) for(unsigned i = 0; i < (n); ++i)
#define FORU(i, j, k) for(unsigned i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(unsigned i = (j); i >= (k); --i)

int main(int, char**){
  long n; cin >> n;
  vector<long> A(n), B(n);
  FOR(i, n) cin >> A[i];
  FOR(i, n) B[i] = i;
  sort(B.begin(), B.end(), [&](long i, long j) -> bool { return A[i] < A[j]; });
  long lst = -1;
  FOR(i, n){
    A[B[i]] = max(lst + 1, A[B[i]]);
    lst = A[B[i]];
  }
  FOR(i, n) cout << A[i] << " ";
  cout << endl;
  return 0;
}