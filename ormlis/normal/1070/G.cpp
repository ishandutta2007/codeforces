#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

bool dp0[100];
int par0[100];
bool dp1[100];
int par1[100];
int mn[100][100];

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  vector<int> s(m);
  vector<int> h(m);
  for (int i = 0; i < m; ++i) {
    cin >> s[i] >> h[i];
    --s[i];
  }
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = 0; i < n; ++i) {
    int cur = A[i];
    mn[i][i] = cur;
    for (int j = i + 1; j < n; ++j) {
      cur += A[j];
      mn[i][j] = min(mn[i][j - 1], cur);
    }
    cur = A[i];
    for (int j = i - 1; j >= 0; --j) {
      cur += A[j];
      mn[i][j] = min(mn[i][j + 1], cur);
    }
  }
  vector<int> hero_id(n, -1);
  for (int i = 0; i < m; ++i)
    hero_id[s[i]] = i;
  for (int id = 0; id < n; ++id) {
    fill(dp0, dp0 + n, false);
    fill(dp1, dp1 + n, false);
    //calc with id
    int first_hero = -1;
    for (int i = id - 1; i >= 0; --i) {
      if (hero_id[i] == -1)
        continue;
      first_hero = i;
      if (h[hero_id[i]] + mn[i][id] >= 0) {
        dp0[i] = true;
        par0[i] = id;
      }
      for (int j = i + 1; j < id; ++j) {
        if (hero_id[j] == -1)
          continue;
        if (dp0[j] && h[hero_id[i]] + mn[i][j - 1] >= 0) {
          dp0[i] = true;
          par0[i] = j;
        }
      }
    }
    for (int i = id - 1; i >= 0; --i) {
      if (hero_id[i] == -1)
        continue;
      if (h[hero_id[i]] + mn[i][id - 1] >= 0) {
        dp1[i] = true;
        par1[i] = id;
      }
      for (int j = i + 1; j < id; ++j) {
        if (hero_id[j] == -1)
          continue;
        if (dp1[j] && h[hero_id[i]] + mn[i][j - 1] >= 0) {
          dp1[i] = true;
          par1[i] = j;
        }
      }
    }
    int last_hero = -1;
    for (int i = id + 1; i < n; ++i) {
      if (hero_id[i] == -1)
        continue;
      last_hero = i;
      if (h[hero_id[i]] + mn[i][id] >= 0) {
        dp0[i] = true;
        par0[i] = id;
      }
      for (int j = i - 1; j > id; --j) {
        if (hero_id[j] == -1)
          continue;
        if (dp0[j] && h[hero_id[i]] + mn[i][j + 1] >= 0) {
          dp0[i] = true;
          par0[i] = j;
        }
      }
    }
    for (int i = id + 1; i < n; ++i) {
      if (hero_id[i] == -1)
        continue;
      if (h[hero_id[i]] + mn[i][id] >= 0) {
        dp1[i] = true;
        par1[i] = id;
      }
      for (int j = i - 1; j > id; --j) {
        if (hero_id[j] == -1)
          continue;
        if (dp1[j] && h[hero_id[i]] + mn[i][j + 1] >= 0) {
          dp1[i] = true;
          par1[i] = j;
        }
      }
    }
    if (A[id] < 0) {
      if (first_hero != -1 && dp0[first_hero] && (last_hero == -1 || dp1[last_hero])) {
        vector<bool> used(m, false);
        vector<int> ans;
        if (last_hero != -1) {
          int cur = last_hero;
          while (cur != id) {
            used[hero_id[cur]] = true;
            ans.emplace_back(hero_id[cur]);
            cur = par1[cur];
          }
        }
        int cur = first_hero;
        while (cur != id) {
          used[hero_id[cur]] = true;
          ans.emplace_back(hero_id[cur]);
          cur = par0[cur];
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < m; ++i) {
          if (!used[i])
            ans.emplace_back(i);
        }
        cout << id + 1 << '\n';
        for (int x : ans)
          cout << x + 1 << ' ';
        cout << '\n';
        return 0;
      }
      if (last_hero != -1 && dp0[last_hero] && (first_hero == -1 || dp1[first_hero])) {
        vector<bool> used(m, false);
        vector<int> ans;
        if (first_hero != -1) {
          int cur = first_hero;
          while (cur != id) {
            used[hero_id[cur]] = true;
            ans.emplace_back(hero_id[cur]);
            cur = par1[cur];
          }
        }
        int cur = last_hero;
        while (cur != id) {
          used[hero_id[cur]] = true;
          ans.emplace_back(hero_id[cur]);
          cur = par0[cur];
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < m; ++i) {
          if (!used[i])
            ans.emplace_back(i);
        }
        cout << id + 1 << '\n';
        for (int x : ans)
          cout << x + 1 << ' ';
        cout << '\n';
        return 0;
      }
    } else if ((first_hero == -1 || dp1[first_hero]) && (last_hero == -1 || dp1[last_hero])) {
      vector<bool> used(m, false);
      vector<int> ans;
      if (first_hero != -1) {
        int cur = first_hero;
        while (cur != id) {
          used[hero_id[cur]] = true;
          ans.emplace_back(hero_id[cur]);
          cur = par1[cur];
        }
      }
      if (last_hero != -1) {
        int cur = last_hero;
        while (cur != id) {
          used[hero_id[cur]] = true;
          ans.emplace_back(hero_id[cur]);
          cur = par1[cur];
        }
      }
      reverse(ans.begin(), ans.end());
      for (int i = 0; i < m; ++i) {
        if (!used[i])
          ans.emplace_back(i);
      }
      cout << id + 1 << '\n';
      for (int x : ans)
        cout << x + 1 << ' ';
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}