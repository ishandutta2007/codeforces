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

long A[1000];

int main(int, char**){
  ios_base::sync_with_stdio(false);
  long n, k; cin >> n >> k;
  FOR(i, n) cin >> A[i];

  long res = A[0];

  FOR(i, n){
    multiset<long> av;
    multiset<long> ng;

    long sum = A[i];

    FOR(j, i) av.insert(A[j]);
    FORU(j, i+1, n-1) av.insert(A[j]);

    ng.insert(A[i]);

    auto cnt = [&](){
      long kk = 0;
      auto it = av.rbegin();
      auto it2 = ng.begin();
      long s = sum;
      if(it != av.rend() && it2 != ng.end() && kk < k)
      for(; it != av.rend() && it2 != ng.end() && kk < k && *it - *it2 > 0; it++, it2++, kk++){
        s += *it - *it2;
      }
      res = max(res, s);
    };

    cnt();
    FORU(j, i+1, n-1) {
      sum += A[j];
      if(av.find(A[j]) != av.end()) av.erase(av.find(A[j]));
      ng.insert(A[j]);
      cnt();
    }
  }

  cout << res << endl;
  return 0;
}