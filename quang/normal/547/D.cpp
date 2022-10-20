#include <bits/stdc++.h>

using namespace std;

const int N = 200001;

int n;
vector <pair<int, int> > a[N * 2];
vector <int> odd;
int used[N * 2], cur[N * 2];
char res[N];

void dfs(int u) {
  while (cur[u] < a[u].size()) {
    int v = a[u][cur[u]].first;
    int pos = a[u][cur[u]].second;
    if (used[pos]) {
      cur[u]++;
      continue;
    }
    if (pos <= n) {
      if (u < N) {
        res[pos] = 'b';
      } else {
        res[pos] = 'r';
      }
    }
    used[pos] = 1;
    dfs(v);
    cur[u]++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(make_pair(y + N, i));
    a[y + N].push_back(make_pair(x, i));
  }
  for (int i = 1; i < N * 2; i++) {
    if (a[i].size() % 2) {
      odd.push_back(i);
    }
    used[i] = cur[i] = 0;
  }
  int cnt = n;
  for (int i = 0; i < odd.size(); i += 2) {
    cnt++;
    a[odd[i]].push_back(make_pair(odd[i + 1], cnt));
    a[odd[i + 1]].push_back(make_pair(odd[i], cnt));
  }
  for (int i = 1; i < N * 2; i++) {
    dfs(i);
  }
  cout << (res + 1);
  return 0;
}