#include <bits/stdc++.h>

using namespace std;

template<typename T>
void print_vector(vector<T> vec) {
  copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
  cout << '\n';
}


template<typename T>
void read_vector(vector<T>& vec) {
  generate(vec.begin(), vec.end(), [&]() {
    T val;
    cin >> val;
    return val;
  });
}

int solve() {
  int k;
  cin >> k;
  int z = sqrt(k);
  if (z * z < k) {
    z++;
  }
  int shift = z * z - k;
  int x = z;
  int y = 1;
  if (shift < z) {
    y += shift;
  } else {
    y = z;
    x -= shift - z + 1;
  }
  cout << x << ' ' << y << '\n';
  return 0;
}

int main() {
  int t;
  cin >> t;
  vector<int> test_cases(t);
  generate(test_cases.begin(), test_cases.end(), solve);
}