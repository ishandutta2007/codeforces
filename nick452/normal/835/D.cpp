#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

const int kMaxLength = 5100;

int length;
int a[kMaxLength];
short lcp[kMaxLength][kMaxLength];
bool is_palindrome[kMaxLength][kMaxLength];
short palindrome[kMaxLength][kMaxLength];
int ret[kMaxLength];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  {
    string s;
    cin >> s;
    length = s.length();
    for (int i = 0; i < length; ++i) {
      a[i] = s[i];
    }
  }
  memset(lcp, 0, sizeof(lcp));
  for (int i = length - 1; i >= 0; --i) {
    for (int j = i; j < length; ++j) {
      lcp[i][j] = (a[i] == a[j] ? lcp[i + 1][j + 1] + 1 : 0);
    }
  }
  memset(is_palindrome, false, sizeof(is_palindrome));
  for (int i = length - 1; i >= 0; --i) {
    for (int j = i; j < length; ++j) {
      is_palindrome[i][j] = (a[i] == a[j] && (i + 1 > j - 1 || is_palindrome[i + 1][j - 1]));
    }
  }
  memset(palindrome, 255, sizeof(palindrome));
  for (int s = length - 1; s >= 0; --s) {
    for (int t = s; t < length; ++t) {
      if (is_palindrome[s][t]) {
        palindrome[s][t] = 0;
      }
      int half_length = (t - s + 1) / 2;
      if (half_length > 0 && palindrome[s][s + half_length - 1] >= 0 && lcp[s][t - half_length + 1] >= half_length) {
        palindrome[s][t] = palindrome[s][s + half_length - 1] + 1;
      }
    }
  }
  memset(ret, 0, sizeof(ret));
  for (int s = length - 1; s >= 0; --s) {
    for (int t = s; t < length; ++t) {
      if (palindrome[s][t] >= 0) {
        ++ret[palindrome[s][t]];
      }
    }
  }
  for (int i = length - 2; i >= 0; --i) {
    ret[i] += ret[i + 1];
  }
  for (int i = 0; i < length; ++i) {
    printf("%d ", ret[i]);
  }
  printf("\n");
  return 0;
}