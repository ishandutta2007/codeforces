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

int main(int, char**){
  ios_base::sync_with_stdio(false);
  long n, m; cin >> n >> m;
  long A[1000];
  FOR(i, n) A[i] = -1;
  FOR(i, m){
    long j; cin >> j;
    FORU(k, j-1, n-1){
      if(A[k] == -1) A[k] = j;
    }
  }
  FOR(i, n){
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}