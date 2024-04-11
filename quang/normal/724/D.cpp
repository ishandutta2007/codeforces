#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int m, n;
char s[N];
vector<int> pos[26];
int has[N];
int dp[N];

bool check(int u) {
  memset(dp, 60, sizeof dp);
  queue <int> q;
  int curPos = 0, curDel = 0;
  dp[0] = 0;
  int f = 0;
  for (int i = 1; i <= n - m + 1; i++) {
    while (curPos < pos[u].size()) {
      if (pos[u][curPos] - m + 1 <= i) {
        q.push(max(1, pos[u][curPos] - m + 1));
        curPos++;
      } else {
        break;
      }
    }
    while (curDel < curPos) {
      if (pos[u][curDel] < i) {
        q.pop();
        curDel++;
      } else {
        break;
      }
    }
    if (q.empty()) {
      if (!has[i]) {
        f = 1;
      } else {
        dp[i] = dp[i - 1];
      }
    } else {
      if (has[i]) {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = 1 + dp[q.front() - 1];
        has[i] = 1;
      }
    }
  }
  return !f;
}

int main() {
  scanf("%d", &m);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  m = min(m, n);
  for (int i = 1; i <= n; i++) {
    pos[s[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < 26; i++) {
    if (check(i)) {
      for (int j = 0; j < i; j++) {
        for (int k = 0; k < pos[j].size(); k++) {
          putchar(j + 'a');
        }
      }
      for (int j = 0; j < dp[n - m + 1]; j++) {
        putchar(i + 'a');
      }
      return 0;
    }
  }
  exit(1);
	return 0;
}