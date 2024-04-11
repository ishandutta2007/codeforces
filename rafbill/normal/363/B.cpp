#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <bitset>
#include <set>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, a, b) for(long i = a; i <= (b); ++i)
#define FORR(i, a, b) for(long i = a; i >= (b); --i)

using namespace std;

long A[1000001];

int main(int, char**){
  int n, k;
  cin >> n >> k;
  FOR(i, n){
    cin >> A[i];
  }
  long m = 0;
  long l = 1;
  long s = 0;
  FOR(i, k) s += A[i];
  m = s;
  FORU(i, k, n-1){
    s += A[i] - A[i-k];
    if(s < m){
      l = i - k + 2;
      m = s;
    }
  }
  cout << l << endl;

  return 0;
}