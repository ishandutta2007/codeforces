/**
 * Each cow has a distinct sleeping point (if all goes from L or R).
 * Assume cows only go from L
 * Every valid subset has exactly 1 correct ordering
 * Count the number of valid subsets
 * 
 * First, delete useless cows.
 * 
 * If we go only from L, then we can send C cows where C is number of distinct colors.
 * The number of ways is product(all(numCow)).
 * 
 * How to merge?
 * 
 * 
 * Process each color separately.
 * Fix lim, split to left and right. Make sure it's filled by left, use a bool to do it.
 * When processing color c, we can:
 * Pick 2 cows, send it. ans += 2
 * Pick 1, send it. ans += 1
 * Pick 0. ans += 0
 * 
 * Brute forcing transition is O(N^2) amortized over all colors. But this can be done in O(N).
 * Then we achieve O(N) per DP.
 * 
 * Now compute DP for every possible split.
 * 
 * Time: O(N^2)
 * 
**/

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
// #pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;

int N, M;
int S[5005];
int F[5005], H[5005];

int Split;
vector<pair<int, int>> Color[5005]; // (goL, goR)
int Second[5005][5005]; // [color, lowerThan] for goR (inclusive)

pair<int, lint> memo[5005][2];

pair<int, lint> dp(int color, bool split) {
  if (color > N) {
    if (split)
      return {0, 1};
    return {-1e6, 0};
  }
  if (memo[color][split] != make_pair(-1, -1ll)) {
    return memo[color][split];
  }

  pair<int, lint> res = dp(color + 1, split);

  // O(N) amortized transition over all colors
  for (int i = 0; i < Color[color].size(); i++) {
    if (Color[color][i].first <= Split) {
      pair<int, lint> cur1 = dp(color + 1, split || (Color[color][i].first == Split)); // goL
      cur1.first++;
      if (res.first < cur1.first) {
        res = cur1;
        res.second = 0;
      }
      if (res.first == cur1.first) {
        res.second += cur1.second;
        res.second %= MOD;
      }
    }

    if (Color[color][i].second > Split) {
      pair<int, lint> cur2 = dp(color + 1, split); // goR
      cur2.first++;
      if (res.first < cur2.first) {
        res = cur2;
        res.second = 0;
      }
      if (res.first == cur2.first) {
        res.second += cur2.second;
      }
    }

    // goL and goR (i goes to goL)
    if (Color[color][i].first <= Split) {
      int i2Cnt = (int) Color[color].size() - Second[color][Split];
      if (Color[color][i].second > Split) {
        i2Cnt--;
      }

      pair<int, lint> cur3 = dp(color + 1, split || (Color[color][i].first == Split)); // goL and goR
      cur3.first += 2;
      cur3.second *= i2Cnt;

      if (i2Cnt == 0) {
        continue;
      }

      if (res.first < cur3.first) {
        res = cur3;
        res.second = 0;
      }
      if (res.first == cur3.first) {
        res.second += cur3.second;
      }
    }
  }

  res.second %= MOD;
  return memo[color][split] = res;
}

pair<lint, int> solve() {
  memo[N + 1][1] = {0, 1};
  memo[N + 1][0] = {-1e6, 0};

  for (int color = N; color >= 1; color--) {
    for (int split = 1; split >= 0; split--) {
      pair<int, lint> res = memo[color + 1][split];

      // O(N) amortized transition over all colors
      for (int i = 0; i < Color[color].size(); i++) {
        if (Color[color][i].first <= Split) {
          pair<int, lint> cur1 = memo[color + 1][split || (Color[color][i].first == Split)]; // goL
          cur1.first++;
          if (res.first < cur1.first) {
            res = cur1;
            res.second = 0;
          }
          if (res.first == cur1.first) {
            res.second += cur1.second;
            res.second %= MOD;
          }
        }

        if (Color[color][i].second > Split) {
          pair<int, lint> cur2 = memo[color + 1][split]; // goR
          cur2.first++;
          if (res.first < cur2.first) {
            res = cur2;
            res.second = 0;
          }
          if (res.first == cur2.first) {
            res.second += cur2.second;
          }
        }

        // goL and goR (i goes to goL)
        if (Color[color][i].first <= Split) {
          int i2Cnt = (int) Color[color].size() - Second[color][Split];
          if (Color[color][i].second > Split) {
            i2Cnt--;
          }

          pair<int, lint> cur3 = memo[color + 1][split || (Color[color][i].first == Split)]; // goL and goR
          cur3.first += 2;
          cur3.second *= i2Cnt;

          if (i2Cnt == 0) {
            continue;
          }

          if (res.first < cur3.first) {
            res = cur3;
            res.second = 0;
          }
          if (res.first == cur3.first) {
            res.second += cur3.second;
          }
        }
      }

      res.second %= MOD;
      memo[color][split] = res;
    }
  }
  return memo[1][Split == 0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> S[i];
  }

  for (int m = 0; m < M; m++) {
    int f, h;
    cin >> f >> h;
    int where = -1;
    for (int i = 1, cnt = 0; i <= N; i++) {
      if (S[i] == f) {
        cnt++;
      }
      if (cnt == h) {
        where = i;
        break;
      }
    }

    int where2 = -1;
    for (int i = N, cnt = 0; i >= 1; i--) {
      if (S[i] == f) {
        cnt++;
      }
      if (cnt == h) {
        where2 = i;
        break;
      }
    }

    if (where != -1 && where2 != -1) {
      Color[f].emplace_back(where, where2);
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < Color[i].size(); j++) {
      Second[i][Color[i][j].second]++;
    }
    for (int j = 1; j <= N; j++) {
      Second[i][j] += Second[i][j - 1];
    }
  }

  pair<int, lint> ans;
  for (int split = 0; split <= N; split++) {
    Split = split;
    // for (int i = 1; i <= N; i++) {
    //   memo[i][0] = memo[i][1] = make_pair(-1, -1);
    // }
    // pair<int, lint> cur = dp(1, split == 0);
    pair<int, lint> cur = solve();
    
    if (ans.first < cur.first) {
      ans = cur;
      ans.second = 0;
    }
    if (ans.first == cur.first) {
      ans.second += cur.second;
    }
  }
  ans.second %= MOD;

  cout << ans.first << " " << ans.second << "\n";
  return 0;
}