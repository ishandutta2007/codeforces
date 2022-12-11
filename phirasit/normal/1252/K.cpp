#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;

  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      cout << (n == 1 ? i : 1LL) << endl;
      return 0;
    }
  }

  cout << n << endl;

  return 0;
}