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
  long long a, b, c;
  cin >> a >> b >> c;
  long long n = (max(a, b) - min(a, b)) * 2;
  if (n < max({a, b, c})) {
    cout << "-1\n";
  } else {
      cout << (c - 1 + n / 2) % n + 1 << '\n';
  }
  return 0;
}

int main() {
  int t;
  cin >> t;
  vector<int> test_cases(t);
  generate(test_cases.begin(), test_cases.end(), solve);
}