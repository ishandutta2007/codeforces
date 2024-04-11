#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(3);
  vector<int> b(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> b[i];
  }

  const auto Minimum = [&](const auto &self, vector<int> &a, vector<int> &b) -> int {
    if (a[0] + a[1] + a[2] == 0) return 0;
    int score = n + 5;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int xx = min(a[i], b[j]);
        if (xx == 0) continue;
        a[i] -= xx;
        b[j] -= xx;
        int add = 0;
        if ((i + 1) % 3 == j) add = xx;
        score = min(score, add + self(self, a, b));
        a[i] += xx;
        b[j] += xx;
      }
    }
    return score;
  };

  const auto Maximum = [&](const auto &self, vector<int> &a, vector<int> &b) -> int {
    if (a[0] + a[1] + a[2] == 0) return 0;
    int score = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int xx = min(a[i], b[j]);
        if (xx == 0) continue;
        a[i] -= xx;
        b[j] -= xx;
        int add = 0;
        if ((i + 1) % 3 == j) add = xx;
        score = max(score, add + self(self, a, b));
        a[i] += xx;
        b[j] += xx;
      }
    }
    return score;
  };
  
  cout << Minimum(Minimum, a, b) << " " << Maximum(Maximum, a, b) << "\n";
  return 0;
}