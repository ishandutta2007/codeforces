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

long DP[4000][4000];

int main(int, char**){
  set<long> P[4000];
  ios_base::sync_with_stdio(false);
  long n, k; cin >> n >> k;
  FORU(i, 1, n) FORU(j, 1, n) {
    if(i % j == 0){
      P[i].insert(j);
    }
  }
  FORU(i, 1, n){
    DP[1][i] = 1;
  }
  FORU(j, 2, k){
    FORU(i, 1, n){
      for(auto it = P[i].begin(); it != P[i].end(); ++it){
        DP[j][i] += DP[j-1][*it];
        DP[j][i] %= 1000000007;
      }
    }
  }
  long r = 0;
  FORU(i, 1, n){ r += DP[k][i]; r %= 1000000007; }
  cout << r << endl;
  return 0;
}