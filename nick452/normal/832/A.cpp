#include <iostream>

using namespace std;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t n, k;
  cin >> n >> k;
  if (n / k % 2 == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}