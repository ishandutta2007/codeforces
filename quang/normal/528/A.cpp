#include <bits/stdc++.h>

using namespace std;

int w, h, n;

struct data {
  multiset <int> l;
  set<int> pos;

  data(int x) {
    l.clear();
    pos.clear();
    pos.insert(x);
    pos.insert(0);
    l.insert(-x);
  }

  void add(int x) {
    pos.insert(x);
    auto left = --pos.find(x);
    auto right = ++pos.find(x);
    auto mid = pos.find(x);
    int val = *right - *left;
    l.erase(l.find(-val));
    val = *mid - *left;
    l.insert(-val);
    val = *right - *mid;
    l.insert(-val);
  }

  int getmax() {
    int x = *l.begin();
    return  -x;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  ///freopen("input", "r", stdin);
  cin >> w >> h >> n;
  data V(w);
  data H(h);
  for (int i = 1; i <= n; i++) {
    char type;
    int x;
    cin >> type >> x;
    if (type == 'H') {
      H.add(x);
    } else {
      V.add(x);
    }
    int a = H.getmax();
    int b = V.getmax();
    cout << 1ll * a * b << endl;
  }
  return 0;
}