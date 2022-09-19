#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <list>
#include <tuple>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>

using namespace std;

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)

void solve(){
  long n, p; cin >> n >> p;
  pair<long, long> B = make_pair(0, 1);
  auto inc_p = [&](pair<long, long>& P){
    P.second += 1;
    if(P.second == n){
      P.first += 1;
      P.second = P.first + 1;
    }
  };
  FOR(i, 2 * n + p){
    cout << B.first+1 << " " << B.second+1 << endl;
    inc_p(B);
  }
}

int main(int, char**){
  long t; cin >> t;
  FOR(i, t){
    solve();
  }
  return 0;
}