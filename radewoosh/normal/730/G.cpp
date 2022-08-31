#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> juz;
  juz.emplace_back(-1, 0);
  while (n--) {
    int a, l;
    scanf("%d%d", &a, &l);
    const int b = a + l - 1;
    bool ok = true;
    for (const auto& p : juz) {
      if (!(b < p.first or p.second < a)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      juz.emplace_back(a, b);
    } else {
      ok = false;
      for (int i = 1; i < (int) juz.size(); i++) {
        if (juz[i].first - juz[i - 1].second - 1 >= l) {
          juz.emplace_back(juz[i - 1].second + 1, juz[i - 1].second + l);
          ok = true;
          break;
        }
      }
      if (!ok) {
        juz.emplace_back(juz.back().second + 1, juz.back().second + l);
      }
    }
    printf("%d %d\n", juz.back().first, juz.back().second);
    sort(juz.begin(), juz.end());
  }
  return 0;
}