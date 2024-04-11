#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
bool used[N];
vector <pair<int, int> > res;
vector <int> ex;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 3; i + i <= n; i++) {
    if (used[i] || i % 2 == 0) {
      continue;
    }
    vector <int> x;
    for (int j = i; j <= n; j += i) {
      if (used[j]) {
        continue;
      }
      used[j] = 1;
      x.push_back(j);
    }
    if (x.size() % 2) {
      ex.push_back(x[1]);
      x.erase(x.begin() + 1);
    }
    for (int i = 0; i < x.size(); i += 2) {
      res.push_back(make_pair(x[i], x[i + 1]));
    }
  }
  for (int i = 2; i <= n; i += 2) {
    if (!used[i]) {
      ex.push_back(i);
    }
  }
  for (int i = 0; i + 1 < ex.size(); i += 2) {
    res.push_back(make_pair(ex[i], ex[i + 1]));
  }
  cout << res.size() << endl;
  for (auto a : res) {
    cout << a.first << " " << a.second << endl;
  }
  return 0;
}