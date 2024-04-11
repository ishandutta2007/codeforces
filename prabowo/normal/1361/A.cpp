#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m;
vector<int> edges[N];
pair<int, int> t[N];

int topic[N];
bool vis[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i].first);
    --t[i].first;
    t[i].second = i;
    topic[i] = -1;
  }
  sort(t, t + n);

  for (int i = 0; i < n; ++i) {
    int u, expectedTopic;
    tie(expectedTopic, u) = t[i];
    for (int v: edges[u]) {
      if (topic[v] != -1) {
        vis[topic[v]] = true;
      }
    }

    int mex = 0;
    for (int i = 0; ; ++i) {
      if (!vis[i]) {
        mex = i;
        break;
      }
    }

    if (mex != expectedTopic) return 0 * printf("-1\n");

    for (int v: edges[u]) {
      if (topic[v] != -1) {
        vis[topic[v]] = false;
      }
    }
    topic[u] = expectedTopic;
  }

  for (int i = 0; i < n; ++i) printf("%d ", t[i].second + 1);
  return 0;
}