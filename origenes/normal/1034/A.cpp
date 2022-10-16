#include <bits/stdc++.h>

using namespace std;

const int max_len = 312345;
const long long upper_limit = 15123456;
int factor[upper_limit], common[upper_limit];
long long a[max_len];
int n;
long long max_val, prev_gcd;

int main() {
//    cout << "he" << endl;
  cin >> n;
  prev_gcd = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    max_val = max(max_val, a[i]);
    prev_gcd = __gcd(prev_gcd, a[i]);
  }

  if (prev_gcd > 1) {
    for (int i = 1; i <= n; ++i) {
      a[i] /= prev_gcd;
    }
  }

//    cout << "he!" << endl;
  for (int j = 2; j <= upper_limit; ++j) {
    if (factor[j]) {
      continue;
    }
    factor[j] = j;
    for (long long val = (long long) j * j; val <= upper_limit; val += j) {
      if (!factor[val]) {
        factor[val] = j;
      }
    }
  }

//    cout << "he!!" << endl;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 1) {
      continue;
    }
    if (factor[a[i]] == a[i]) {
      common[a[i]]++;
      continue;
    }
    long long cur = a[i];
    common[factor[cur]]++;
    while (cur > 1) {
      if (factor[cur] != factor[a[i]]) {
        common[factor[cur]]++;
        a[i] = cur;
      }
      cur /= factor[cur];
    }
  }

//    cout << "he!!!" << endl;
  int max_size = 0;
  for (int val = 2; val <= max_val; ++val) {
//    max_size = max(max_size, common[val]);
    if (common[val] >= n) {
      cout << val << ' ' << common[val] << endl;
      for (int i = 2; i < upper_limit; i++) if (factor[i] == val) cout << i << ' ';
      assert(0);
    }
    max_size = max(max_size, common[val]);
  }

//    cout << "he!!!!" << endl;
//    cout << max_size << endl;
  cout << (max_size ? n - max_size : -1) << endl;

  return 0;
}