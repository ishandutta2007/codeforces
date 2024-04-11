#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &u : a) {
    cin >> u;
  }
  for (auto &u : b) {
    cin >> u;
  }
  int low = -1, high = n + 2;
  while (high - low > 1) {
    int mid = low + high >> 1;
    vector<int> aa = a;
    vector<int> bb = b;
    for (int i = 1; i <= mid; i++) {
      aa.push_back(100);
    }
    for (int i = 1; i <= mid; i++) {
      bb.push_back(0);
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    long long suma = 0, sumb = 0;
    int need = aa.size() - (aa.size() / 4);
    for (int i = aa.size() - need; i < aa.size(); i++) {
      suma += aa[i];
      sumb += bb[i];
    }
    if (suma >= sumb) high = mid;
    else low = mid;
  }
  cout << high << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}