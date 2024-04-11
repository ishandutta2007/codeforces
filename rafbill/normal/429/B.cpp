#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>

using namespace std;

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = j; i <= (k); ++i)
#define FORD(i, j, k) for(long i = j; i >= (k); --i)

long A[1000][1000];

long DP11[1002][1002];
long DP12[1002][1002];

long DP21[1002][1002];
long DP22[1002][1002];

int main(int, char**){
  int n, m; cin >> n >> m;
  FOR(i, n) FOR(j, m) cin >> A[i][j];

  FOR(i, n+2) FOR(j, m+2) DP11[i][j] = 0;
  FOR(i, n+2) FOR(j, m+2) DP12[i][j] = 0;
  FOR(i, n+2) FOR(j, m+2) DP21[i][j] = 0;
  FOR(i, n+2) FOR(j, m+2) DP12[i][j] = 0;
  FOR(i, n) FOR(j, m) DP11[i+1][j+1] = A[i][j] + max(DP11[i][j+1], DP11[i+1][j]);
  FORD(i, n-1, 0) FORD(j, m-1, 0) DP12[i+1][j+1] = A[i][j] + max(DP12[i+1][j+2], DP12[i+2][j+1]);
  FORD(i, n-1, 0) FOR(j, m) DP21[i+1][j+1] = A[i][j] + max(DP21[i+2][j+1], DP21[i+1][j]);
  FOR(i, n) FORD(j, m-1, 0) DP22[i+1][j+1] = A[i][j] + max(DP22[i][j+1], DP22[i+1][j+2]);

  // FOR(i, n) {FOR(j, m) cout << DP11[i+1][j+1] << " "; cout << endl;} cout << endl;
  // FOR(i, n) {FOR(j, m) cout << DP12[i+1][j+1] << " "; cout << endl;} cout << endl;
  // FOR(i, n) {FOR(j, m) cout << DP21[i+1][j+1] << " "; cout << endl;} cout << endl;
  // FOR(i, n) {FOR(j, m) cout << DP22[i+1][j+1] << " "; cout << endl;} cout << endl;

  long ma = 0;
  FORU(i, 1, n-2) FORU(j, 1, m-2) ma = max<long>(ma, max<long>(
    DP11[i][j+1] + DP12[i+2][j+1] + DP21[i+1][j] + DP22[i+1][j+2],
    DP21[i+2][j+1] + DP22[i][j+1] + DP11[i+1][j] + DP12[i+1][j+2]
  ));
  cout << ma << endl;

  return 0;
}