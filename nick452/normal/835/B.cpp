#include <iostream>
#include <string.h>

using namespace std;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int sum_of_digits;
  string target;
  cin >> sum_of_digits >> target;
  int count[10];
  memset(count, 0, sizeof(count));
  for (char c : target) {
    ++count[c - '0'];
  }
  int length = target.length(), ret = 0;
  for (int digit = 9; digit >= 0; --digit) {
    for (; count[digit] > 0; --count[digit]) {
      --length;
      if (sum_of_digits - digit <= 9 * length) {
        sum_of_digits -= digit;
      } else {
        sum_of_digits -= 9;
        ++ret;
      }
    }
  }
  cout << ret << endl;
  return 0;
}