#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbPoints;
  cin >> nbPoints;
  vector<pair<int, int>> points(nbPoints);
  for (auto &[x, y] : points) {
    cin >> x >> y;
    x /= 2, y /= 2;
  }

  int ret = 0;
  for (int fst = 0; fst < nbPoints; ++fst) {
    auto [x1, y1] = points[fst];

    int cnt[2][2] = {{0, 0}, {0, 0}};

    for (int snd = fst + 1; snd < nbPoints; ++snd) {
      auto [x2, y2] = points[snd];
      int px = abs(x2 - x1) % 2;
      int py = abs(y2 - y1) % 2;
      cnt[px][py] += 1;
    }

    for (int px1 = 0; px1 < 2; ++px1)
      for (int py1 = 0; py1 < 2; ++py1)
        for (int px2 = px1; px2 < 2; ++px2)
          for (int py2 = py1; py2 < 2; ++py2)
            if ((gcd(px1, py1) + gcd(px2, py2) + gcd(px1 + px2, py1 + py2)) %
                    2 ==
                0) {
              if (px1 == px2 and py1 == py2)
                ret += cnt[px1][py1] * (cnt[px1][py1] - 1) / 2;
              else
                ret += cnt[px1][py1] * cnt[px2][py2];
            }
  }
  cout << ret << endl;
}