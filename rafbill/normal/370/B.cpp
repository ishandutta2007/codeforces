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

int main(int, char**){
  long n; cin >> n;
  vector<bitset<100>> A(n);
  vector<bitset<100>> B(n);
  FOR(i, n){
    long m; cin >> m;
    A[i].reset();
    FOR(j, m){
      long k; cin >> k;
      A[i][k-1] = true;
    }
    B[i] = ~A[i];
  }
  FOR(i, n){
    long p = true;
    FOR(j, n){
      if(j != i){
        if(!(B[i] & A[j]).any()){
          p = false;
          break;
        }
      }
    }
    cout << (p?"YES":"NO")<<endl;
  }
  return 0;
}