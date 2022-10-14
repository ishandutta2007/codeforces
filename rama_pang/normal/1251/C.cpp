#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    string t;
    queue<char> o, e;
    for (auto& i : s) {
      if ((i - '0') % 2 == 0) {
        e.emplace(i);
      } else {
        o.emplace(i);
      }
    }
    while (!o.empty() || !e.empty()) {
      if (o.empty()) {
        t.push_back(e.front());
        e.pop();
        continue;
      }
      if (e.empty()) {
        t.push_back(o.front());
        o.pop();
        continue;
      }
      if (e.front() < o.front()) {
        t.push_back(e.front());
        e.pop();
        continue;
      }
      t.push_back(o.front());
      o.pop();
    }
    cout << t << "\n";
  }
}