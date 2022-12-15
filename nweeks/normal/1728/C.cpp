#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int x) { return 1 + (int)log10(x); }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;
  multiset<int> valA(a.begin(), a.end());
  multiset<int> valB(b.begin(), b.end());
  int sol = 0;
  while (valA.size() or valB.size()) {
    if (*valA.rbegin() < *valB.rbegin())
      valA.swap(valB);
    int x = *valA.rbegin();
    valA.erase(valA.find(x));
    if (valB.count(x)) {
      valB.erase(valB.find(x));
      continue;
    }
    valA.insert(f(x));
    sol++;
  }

  cout << sol << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}