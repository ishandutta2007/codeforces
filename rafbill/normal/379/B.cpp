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

long A[300];
long B[300];

int main(int, char**){
  long n; cin >> n;
  FOR(i, n) cin >> A[i];
  FOR(i, n) B[i] = 0;
  FOR(i, 300){
    FOR(j, n){
      if(B[j] < A[j]){ cout << "P"; B[j] += 1; }
      if(j != n-1) cout << "R";
    }
    FOR(j, n-1){
      cout << "L";
    }
  }
  cout << endl;
  return 0;
}