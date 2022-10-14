#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int MAXN = 105 * 105;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int mx = 0, fil = 0;
  string S;
  map<string, int> cnt;
  map<string, set<pair<string, int>>> folders;
  while (cin >> S) {
    string cur;
    vector<string> A;
    for (auto i : S) {
      if (i == '\\') {
        A.emplace_back(cur);
      } else {
        cur.push_back(i);
      }
    }
    A.emplace_back(cur);
    cnt[A[1]] += 1;
    for (int i = 2; i + 1 < (int) A.size(); i++) {
      folders[A[1]].insert({A[i], i});
    }
    fil = max(fil, cnt[A[1]]);
    mx = max(mx, (int) folders[A[1]].size());
  }
  cout << mx << " " << fil << "\n";
  return 0;
}