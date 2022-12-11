#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, int>> stk;

int main() {
  string str;
  cin >> str;

  for (int i = 0, c; i < str.length(); ++i) {
    c = (i == 0 || str[i] != str[i-1] ? 1 : c+1);
    if (i+1 == str.length() || str[i+1] != str[i]) {
      stk.push_back({str[i], c});
    }
  }

  if (stk.size() % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0, j = stk.size() -1; i < j; ++i, --j) {
    if (stk[i].first != stk[j].first || stk[i].second + stk[j].second < 3) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = stk[stk.size()/2].second + 1;
  if (ans < 3) ans = 0;
  cout << ans << endl;

  
  return 0;
}