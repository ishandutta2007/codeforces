#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  std::string s;
  std::cin >> s;
  auto t = s;
  sort(t.begin(), t.end());
  if (s != t) {
    std::cout << "NO\n";
    return 0;
  }

  int cnt[3]{};
  for (char c : s)
    ++cnt[c-'a'];
  
  std::cout << ((cnt[0] && cnt[1]) && (cnt[0] == cnt[2] || cnt[1] == cnt[2]) ? "YES" : "NO") << '\n';
}