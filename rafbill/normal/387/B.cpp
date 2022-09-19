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

long A[3005];
long B[3005];

int main(int, char**){
  long n, m;
  cin >> n >> m;
  FOR(i, n) cin >> A[n-i-1];
  FOR(i, m) cin >> B[m-i-1];
  long j = 0;
  long k = 0;
  FOR(i, n){
    if(j == m || B[j] < A[i]){
      k++;
      continue;
    }
    j++;
  }
  cout << k << endl;
  return 0;
}