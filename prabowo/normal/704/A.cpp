#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, q;

vector<int> notif[N];

int main() {
  scanf("%d %d", &n, &q);

  set<int> events;
  int cnt = 0;

  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);

    if (t == 1) {
      int x;
      scanf("%d", &x);

      events.insert(cnt);
      notif[x].push_back(cnt);
      ++cnt;
    } else if (t == 2) {
      int x;
      scanf("%d", &x);

      for (int u: notif[x]) {
        events.erase(u);
      }
      notif[x].clear();
    } else if (t == 3) {
      int x;
      scanf("%d", &x);

      while (events.size() && *events.begin() < x) {
        events.erase(events.begin());
      }
    }

    printf("%d\n", (int) events.size());
  }
  return 0;
}