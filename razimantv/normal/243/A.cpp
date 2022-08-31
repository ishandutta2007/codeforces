#include <cstring>
#include <iostream>
#include <map>
#include <set>

int main() {
  std::ios::sync_with_stdio(false);
  int N;
  std::cin >> N;

  int prev[20];
  memset(prev, -1, sizeof prev);
  std::map<int, int> bitmap;
  bitmap[-1] = (1 << 20) - 1;
  std::set<int> poss;

  for (int i = 0; i < N; ++i) {
    int a;
    std::cin >> a;
    if (a == 0) {
      poss.insert(0);
      continue;
    }

    bitmap[i] = 0;
    for (int j = 0; j < 20; ++j) {
      if (a & (1 << j)) {
        bitmap[prev[j]] ^= (1 << j);
        if (bitmap[prev[j]] == 0) bitmap.erase(prev[j]);
        bitmap[i] |= (1 << j);
        prev[j] = i;
      }
    }

    int mask = 0;
    for (auto mit = bitmap.rbegin(); mit != bitmap.rend(); ++mit) {
      if (mit->first == -1) continue;
      mask |= mit->second;
      poss.insert(mask);
    }
  }

  std::cout << poss.size() << std::endl;
  return 0;
}