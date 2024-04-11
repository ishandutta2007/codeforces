#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> B(N);

  set<array<int, 2>> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.insert({a, i});
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  sort(begin(B), end(B));

  vector<array<int, 3>> ans;

  auto No = [&]() {
    // for (auto i : ans) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    cout << "NO\n";
    exit(0);
  };

  for (int i = 0; i < N; i++) {
    int tar = B[i];
    auto it = A.lower_bound({tar, -1});
    if (it != end(A) && (*it)[0] == tar) {
      A.erase(it);
      continue;
    }
    auto it2 = it--;
    if (it2 == begin(A) || it2 == end(A)) {
      No();
    }
    if (abs(tar - (*it)[0]) <= abs(tar - (*it2)[0])) {
      auto aa = *it;
      auto bb = *it2;
      A.erase(aa);
      A.erase(bb);
      ans.push_back({aa[1], bb[1], tar - aa[0]});
      bb[0] -= tar - aa[0];
      A.insert(bb);
    } else {
      auto aa = *it;
      auto bb = *it2;
      A.erase(aa);
      A.erase(bb);
      ans.push_back({aa[1], bb[1], bb[0] - tar});
      aa[0] += bb[0] - tar;
      A.insert(aa);
    }
  }

  cout << "YES\n";
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << "\n";
  }
  return 0;
}