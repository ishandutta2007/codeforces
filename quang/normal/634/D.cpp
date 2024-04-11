#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n,d, m;
pair<int, int> gas[N];
set<pair<int, int> > s;
int rest = 0;
long long res = 0;

void burn(int u) {
  if (u > n) {
    cout << -1 << endl;
    exit(0);
  }
  while (1) {
    auto pos = s.begin();
    int num = pos->second;
    int cost = pos->first;
    if (num < u) {
      u -= num;
      res += 1ll * cost * num;
      s.erase(pos);
      rest += num;
    } else {
      res += 1ll * cost * u;
      rest += u;
      num -= u;
      s.erase(pos);
      if (num) {
        s.insert(make_pair(cost, num));
      }
      break;
    }
  }
}

void buy(int u) {
  pair<int, int> x = make_pair(gas[u].second, rest);
  rest = 0;
  while (!s.empty()) {
    auto pos = s.rbegin();
    int cost = pos->first;
    int num = pos->second;
    if (cost >= x.first) {
      x.second += num;
      s.erase(make_pair(cost, num));
    } else {
      break;
    }
  }
  s.insert(x);
}

int main() {
  scanf("%d %d %d", &d, &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &gas[i].first, &gas[i].second);
  }
  sort(gas + 1, gas + m + 1);
  gas[m + 1] = make_pair(d, 1e9 + 10);
  s.insert(make_pair(0, n));
  for (int i = 1; i <= m + 1; i++) {
    burn(gas[i].first - gas[i - 1].first);
    buy(i);
//    for (auto x : s) {
//      cout << x.first << " " << x.second << endl;
//    }
//    cout << endl;
  }
  cout << res << endl;
  return 0;
}