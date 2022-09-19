#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <functional>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

long A[50001][11];

int main(int, char**){
  ios_base::sync_with_stdio(false);
  long m, n; cin >> m >> n;
  FOR(i, m) FOR(j, n) cin >> A[i+1][j+1];
  FOR(i, m) A[i+1][0] = 0;
  FOR(j, n) A[0][j+1] = 0;
  FOR(i, m) FOR(j, n) A[i+1][j+1] += max(A[i][j+1], A[i+1][j]);
  FOR(i, m) cout << A[i+1][n] << " ";
  cout << endl;
  return 0;
}