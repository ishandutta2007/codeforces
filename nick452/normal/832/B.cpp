#include <iostream>
#include <string.h>

using namespace std;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  bool is_good[128];
  memset(is_good, false, sizeof(is_good));
  string good_letters;
  cin >> good_letters;
  for (char c : good_letters) {
    is_good[c] = true;
  }
  string pattern;
  cin >> pattern;
  int star_position = static_cast<int>(pattern.find('*'));
  int n;
  cin >> n;
  for (int query_num = 0; query_num < n; ++query_num) {
    string query;
    cin >> query;
    bool is_matched;
    if (star_position < 0) {
      if (pattern.length() != query.length()) {
        is_matched = false;
      } else {
        is_matched = true;
        for (int i = 0; i < pattern.length(); ++i) {
          if (!(pattern[i] == '?' ? is_good[query[i]] : pattern[i] == query[i])) {
            is_matched = false;
          }
        }
      }
    } else {
      if (pattern.length() - 1 > query.length()) {
        is_matched = false;
      } else {
        is_matched = true;
        for (int i = 0; i < star_position; ++i) {
          if (!(pattern[i] == '?' ? is_good[query[i]] : pattern[i] == query[i])) {
            is_matched = false;
          }
        }
        int offset = static_cast<int>(query.length()) - static_cast<int>(pattern.length());
        for (int i = star_position + 1; i < pattern.length(); ++i) {
          if (!(pattern[i] == '?' ? is_good[query[i + offset]] : pattern[i] == query[i + offset])) {
            is_matched = false;
          }
        }
        for (int i = star_position; i <= star_position + offset; ++i) {
          if (is_good[query[i]]) {
            is_matched = false;
          }
        }
      }
    }
    if (is_matched) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}