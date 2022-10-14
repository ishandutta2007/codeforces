#include <bits/stdc++.h>
using namespace std;

int n;
int vis[1005][1005];
pair<int, int> go[1005][1005];
char ans[1005][1005];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> go[i][j].first >> go[i][j].second;
      ans[i][j] = '?';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (go[i][j].first != -1) {
        ans[go[i][j].first][go[i][j].second] = 'X';
      }
    }
  }


  function<void(int, int)> dfs = [&](int i, int j) {
    if (ans[i][j] == '?') {
      return;
    }
    vis[i][j] = 1;
    if (go[i + 1][j] == go[i][j] && vis[i + 1][j] == 0 && ans[i + 1][j] == '?') {
      ans[i + 1][j] = 'U';
      dfs(i + 1, j);
    }
    if (go[i - 1][j] == go[i][j] && vis[i - 1][j] == 0 && ans[i - 1][j] == '?') {
      ans[i - 1][j] = 'D';
      dfs(i - 1, j);
    }
    if (go[i][j + 1] == go[i][j] && vis[i][j + 1] == 0 && ans[i][j + 1] == '?') {
      ans[i][j + 1] = 'L';
      dfs(i, j + 1);
    }
    if (go[i][j - 1] == go[i][j] && vis[i][j - 1] == 0 && ans[i][j - 1] == '?') {
      ans[i][j - 1] = 'R';
      dfs(i, j - 1);
    }
  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (ans[i][j] == 'X') {
        if (go[i][j] == make_pair(i, j)) {
          dfs(i, j);
        } else {
          cout << "INVALID\n";
          return 0;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (go[i][j] == make_pair(-1, -1)) {
        if (go[i][j] == go[i + 1][j] && ans[i][j] == '?' && ans[i + 1][j] == '?') {
          ans[i][j] = 'D';
          ans[i + 1][j] = 'U';
        }
        if (go[i][j] == go[i - 1][j] && ans[i][j] == '?' && ans[i - 1][j] == '?') {
          ans[i][j] = 'U';
          ans[i - 1][j] = 'D';
        }
        if (go[i][j] == go[i][j + 1] && ans[i][j] == '?' && ans[i][j + 1] == '?') {
          ans[i][j + 1] = 'L';
          ans[i][j] = 'R';
        }
        if (go[i][j] == go[i][j - 1] && ans[i][j] == '?' && ans[i][j - 1] == '?') {
          ans[i][j - 1] = 'R';
          ans[i][j] = 'L';
        }
        dfs(i, j);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (ans[i][j] == '?') {
        cout << "INVALID\n";
        return 0;
      }
    }
  }

  cout << "VALID\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }


}