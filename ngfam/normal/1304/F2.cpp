#include<bits/stdc++.h>

using namespace std;

const int maxn = 55;
const int maxm = 40002;

int n, m, k;
int s[maxn][maxm];
int f[maxn][maxm];

int cst(int i, int j) {
  return s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> s[i][j];
      s[i][j] += s[i][j - 1];
    }
    for(int j = m + 1; j <= m + m; ++j) s[i][j] = s[i][j - 1];
  }

  for(int i = 1; i <= m; ++i) {
    f[1][i] = cst(1, i);
  }

  for(int i = 2; i <= n; ++i) {
    int best = 0;
    for(int j = 1; j <= m; ++j) {
      f[i][j] = f[i - 1][j] + s[i + 1][j + k - 1] - s[i + 1][j - 1];
      if(j - k > 0) best = max(best, f[i - 1][j - k]);
      f[i][j] = max(f[i][j], cst(i, j) + best);
    }
    best = 0;
    for(int j = m; j >= 1; --j) {
      if(j + k <= m) best = max(best, f[i - 1][j + k]);
      f[i][j] = max(f[i][j], cst(i, j) + best);
    }


    deque<int> que;
    for(int j = 1; j <= m; ++j) {
      while(!que.empty() && que.front() <= j - k) que.pop_front();
      if(!que.empty()) {
        int id = que.front();
        f[i][j] = max(f[i][j], f[i - 1][id] + cst(i, j) - s[i][id + k - 1] + s[i][j - 1]);
      }
      while(!que.empty()) {
        int id = que.back();
        if(f[i - 1][j] - s[i][j + k - 1] > f[i - 1][id] - s[i][id + k - 1]) que.pop_back();
        else break;
      }
      que.push_back(j);
    }

    que.clear();
    for(int j = m; j >= 1; --j) {
      while(!que.empty() && que.front() >= j + k) que.pop_front();
      if(!que.empty()) {
        int id = que.front();
        f[i][j] = max(f[i][j], f[i - 1][id] + cst(i, j) - s[i][j + k - 1] + s[i][id - 1]);
      }
      while(!que.empty()) {
        int id = que.back();
        if(f[i - 1][j] + s[i][j - 1] > f[i - 1][id] + s[i][id - 1]) que.pop_back();
        else break;
      }
      que.push_back(j);
    }
  }

  cout << *max_element(f[n], f[n] + m + 1) << endl;

  return 0;
}