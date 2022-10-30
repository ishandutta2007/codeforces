#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

const long long MOD = 998244353;
const int MAXN = 300000;

long long fact[MAXN + 1];

int main(){
  fact[0] = 1;
  for (int i = 1; i <= MAXN; ++i)
    fact[i] = (fact[i - 1] * i) % MOD;

  int n;
  cin >> n;
  vector<pair<int, int>> A(n);
  vector<pair<int, int>> B(n);
  for (int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    A[i] = make_pair(x, y);
    B[i] = make_pair(y, x);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  bool sortedGood = true;
  for (int i = 1; i < n; ++i){
    if (A[i].second < A[i - 1].second)
      sortedGood = false;
  }
  long long cntBest = sortedGood;
  if (sortedGood){
    int len = 1;
    int i = 1;
    while (i < n){
      if (A[i] == A[i - 1])
        ++len;
      else{
        cntBest = (cntBest * fact[len]) % MOD;
        len = 1;
      }
      ++i;
    }
    cntBest = (cntBest * fact[len]) % MOD;
  }
  long long cnt1 = 1;
  int len = 1;
  int i = 1;
  while (i < n){
    if (A[i].first == A[i - 1].first)
      ++len;
    else{
      cnt1 = (cnt1 * fact[len]) % MOD;
      len = 1;
    }
    ++i;
  }
  cnt1 = (cnt1 * fact[len]) % MOD;
  long long cnt2 = 1;
  len = 1;
  i = 1;
  while (i < n){
    if (B[i].first == B[i - 1].first)
      ++len;
    else{
      cnt2 = (cnt2 * fact[len]) % MOD;
      len = 1;
    }
    ++i;
  }
  cnt2 = (cnt2 * fact[len]) % MOD;
  cout << (fact[n] - cnt1 - cnt2 + cntBest + MOD + MOD) % MOD;
  return 0;
}