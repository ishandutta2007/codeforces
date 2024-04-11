#include <bits/stdc++.h>
using namespace std;

/*
    1011; ans = 0

    _122; ans = 1

    _34_; ans = 3

    _7__; ans = 7

    ____; ans = 14

    1...n -> prefix sum (# of 1's)
    Input: i, j

    1111 -> _222 -> __44 -> ___8

    a = 3
    b = 1
*/

const int MOD = 1000000007;
int n, q; 
string s;
vector<int> prefix_sum;
int pw[100005];

// (A * B) % M = ((A % M) * (B % M)) % M
// 2^(a + 1) % M = ((2^a % M) * (2 % M)) % M
// 1 2 4 8 16 ... 

/*
int pw[100005]; // 1 2 4 8 16 -> 

void init() {
      pw[0] = 1;
      for (int i = 1; i <= 100004; i++) {
            pw[i] = (pw[i-1] * 2) % M;
      }
}
*/

void init() {
  pw[0] = 1;
  for (int i = 1; i <= 100004; ++i) {
    pw[i] = (pw[i - 1] * 2) % MOD;
  }
}

long long maxEnjoyment(int l, int r) {
  // have: # of 0's = b
  // have: # of 1's = a
  // sum of 0's at the end = b * a
  // 1 + 2 + 4 + 8 + 16 + ... + 2^(a - 1) = 2^a - 1
  // 2^0 + ... 
  // 11111111 (length a)
  // 100000000 - 1
  // 111000
  // _22111 -> 1
  // __4333 -> 2
  // ___777 -> 4
  // ____1414 -> 7
  // _____2828 -> 14
  // ______56 -> 28
  // [1+2+4] + 7+14+28+56+...
  // 0's before eating:
  // 1 3 7 15 31 ... 
  // 2^(a) - 1
  // 2^1 - 1 => 2^2 - 1 => 2^3 - 1
  //
  // v v v v
  // _ 2v 2v 2v -> 2v
  // _ _ 4v 4v -> 4v
  // _ _ _ 8v -> 8v
  // _ _ _ _ -> all 16v
  // 
  // 0's after eating:
  // 

  // v*(2^0 + 2^1 + 2^2 + 2^3 + ... + 2^(b-1)) = v * (2^(b) - 1)

  int a = prefix_sum[r] - prefix_sum[l - 1];
  int b = (r - l + 1) - a;
  int v = pw[a] - 1;

  long long first = pw[a] - 1;
  long long second = (((1LL*v) % MOD) * ((pw[b] - 1) % MOD)) % MOD;
  return (first + second) % MOD;
}

int main() {
  int l, r;
  cin >> n >> q;
  cin >> s;
  prefix_sum = vector<int>(n + 1, 0);
  for (int i = 1; i < n + 1; ++i) {
    prefix_sum[i] += prefix_sum[i - 1] + (s[i - 1] - '0');
  }
  init();
  while (q--) {
    cin >> l >> r;
    cout << maxEnjoyment(l, r) << endl;
  }
	return 0;
}