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

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)


int main(int, char**){
  long n, k; cin >> n >> k;
  long A[1000]; FOR(i, n) { cin >> A[i]; A[i] -= 1; }
  long best = 0; long bestcount = 0;
  FOR(i, 1000){
    long cnt = 0;
    FOR(j, n){ cnt += A[j] == i + j * k; }
    if(cnt > bestcount){
      bestcount = cnt;
      best = i;
    }
  }
  cout << n-bestcount << endl;
  FOR(j, n){
    if(A[j] < best + j * k){
      cout << "+ " << j+1 << " " << (best + j * k - A[j]) << endl;
    }else if(A[j] > best + j * k){
      cout << "- " << j+1 << " " << (A[j] - best - j * k) << endl;
    }
  }
  return 0;
}