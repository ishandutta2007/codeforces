#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int DEBUG = 0;

void Main() {
  lint N, A, B, C;
  if (!DEBUG) {
    cin >> N >> A >> B >> C;
  } else {
    N = 15;
    A = rnd() % int(1e3);
    B = rnd() % int(1e3);
    C = rnd() % int(1e3);
  }

  const auto Solve = [&](string S) -> lint {
    lint ans = 0;
    lint freeOne = 0;
    lint freeZero = 0;
    lint paidZero = 0;
    lint makeNewOne = 0;
    vector<int> gap;
    for (int i = 0; i < int(S.size()); i++) {
      int j = i;
      while (j + 1 < int(S.size()) && S[i] == S[j + 1]) {
        j += 1;
      }
      if (S[i] == '0') {
        if (i > 0 && j + 1 < int(S.size())) {
          if (i == j) {
            makeNewOne += 1;
          } else {
            gap.emplace_back(j - i);
          }
        } else {
          freeZero += j - i;
          paidZero += 1;
        }
      } else {
        freeOne += j - i;
      }
      i = j;
    }

    lint score = 0;
    lint usedFreeZero = 0;
    sort(begin(gap), end(gap));
    reverse(begin(gap), end(gap));

    int skipZeroPhase = 0;
    int lastNewlyRemoved = -1;
    while (true) {
      // Delete 0
      int newlyRemoved = 0;
      if (!skipZeroPhase) {
        if (!gap.empty()) {
          assert(gap.back() > 0);
          gap.back()--;
          score += A;
          usedFreeZero += 1;
          if (gap.back() == 0) {
            makeNewOne += 1;
            newlyRemoved = 1;
            gap.pop_back();
          }
        } else {
          if (freeZero > 0) {
            freeZero--;
            score += A;
            usedFreeZero += 1;
          } else if (makeNewOne > 0) {
            makeNewOne--;
            score -= C;
            freeOne += 1;
          } else if (paidZero > 0) {
            paidZero--;
            score -= C;
          } else {
            break;
          }
        }
      } else {
        skipZeroPhase = 0;
        newlyRemoved = lastNewlyRemoved;
      }
      ans = max(ans, score);
      // Delete 1
      if (freeOne > 0) {
        freeOne--;
        score += B;        
      } else {
        if (makeNewOne - newlyRemoved > 0) {
          if (usedFreeZero > 0) {
            score -= C;
            score += B;
            makeNewOne -= 1;
            skipZeroPhase = 1;
            lastNewlyRemoved = newlyRemoved;
          } else {
            break;            
          }
        } else {
          break;
        }
      }
      ans = max(ans, score);
    }
    return ans;
  };

  lint ans = 0;

  string S;
  if (!DEBUG) {
    cin >> S;
  } else {
    for (int i = 0; i < N; i++) {
      if (rnd() & 1) {
        S.push_back('1');
      } else {
        S.push_back('0');
      }
    }
  }

  const auto Brute = [&](string S) -> lint {
    map<pair<string, int>, lint> memo;
    const auto Dfs = [&](const auto &self, string S, int last) -> lint {
      if (memo.count({S, last})) {
        return memo[{S, last}];
      }
      lint ans = 0;
      for (int i = 0; i + 1 < int(S.size()); i++) {
        if (S[i] == '0' && S[i + 1] == '0' && last != 0) {
          string X;
          for (int j = 0; j < int(S.size()); j++) {
            if (i == j) continue;
            X.push_back(S[j]);
          }
          ans = max(ans, A + self(self, X, 0));
        }
      }
      for (int i = 0; i + 1 < int(S.size()); i++) {
        if (S[i] == '1' && S[i + 1] == '1' && last != 1) {
          string X;
          for (int j = 0; j < int(S.size()); j++) {
            if (i == j) continue;
            X.push_back(S[j]);
          }
          ans = max(ans, B + self(self, X, 1));
        }
      }
      for (int i = 0; i < int(S.size()); i++) {
        if (S[i] == '0' && last != 0) {
          string X;
          for (int j = 0; j < int(S.size()); j++) {
            if (i == j) continue;
            X.push_back(S[j]);
          }
          ans = max(ans, -C + self(self, X, 0));
        }
      }
      return memo[{S, last}] = ans;
    };
    return Dfs(Dfs, S, -1);
  };

  ans = max(ans, Solve(S));
  for (int i = 0; i + 1 < N; i++) {
    if (S[i] == '1' && S[i + 1] == '1') {
      string X;
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        X.push_back(S[j]);
      }
      ans = max(ans, Solve(X) + B);
      break;
    }
  }

  // if (DEBUG && Brute(S) != ans) {
  //   cout << Brute(S) << ' ' << ans << '\n';
  //   cout << N << ' ' << A << ' ' << B << ' ' << C << '\n';
  //   cout << S << '\n';
  //   exit(0);
  // }

  // cout << Brute(S) << '\n';
  cout << ans << '\n';

}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
/*


15 510 786 630
10

786+510+786+510+786-630+786-630+786-630+786-630+786
*/