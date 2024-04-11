#include <bits/stdc++.h>

using namespace std;

int h, q;
vector<pair<long long, long long> > a;
vector<pair<long long, long long> > b;
long long lmax, rmin;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> h >> q;
  lmax = (1ll << (h - 1));
  rmin = (1ll << h) - 1;
  for (int i = 1; i <= q; i++) {
    int lv, ans;
    long long l, r;
    cin >> lv >> l >> r >> ans;
    l = (l << (h - lv));
    r = ((r + 1) << (h - lv)) - 1;
    if (ans) {
      lmax = max(lmax, l);
      rmin = min(rmin, r);
    } else {
      a.push_back(make_pair(l, r));
    }
  }
  sort(a.begin(), a.end());
  if(rmin < lmax) {
    puts("Game cheated!");
    return 0;
  }
  long long last = -1;
  for (int i = 0 ; i < a.size(); i++) {
    long long l = a[i].first;
    long long r = a[i].second;
    if (l > last + 1) {
      b.push_back(make_pair(l, r));
    } else {
      b.back().second = max(b.back().second, r);
    }
    last = max(last, r);
  }
  for (int i = 0; i < b.size(); i++) {
    long long l = b[i].first;
    long long r = b[i].second;
    if (l <= lmax && rmin <= r) {
      puts("Game cheated!");
      return 0;
    }
    if (lmax < l && r < rmin) {
      cout << "Data not sufficient!" << endl;
      return 0;
    }
    if (r < lmax || l > rmin) {
      continue;
    }
    if (r < rmin) {
      lmax = r + 1;
    } else {
      rmin = l - 1;
    }
  }
  if (lmax == rmin) {
    cout << lmax << endl;
  } else {
    cout << "Data not sufficient!" << endl;
  }
  return 0;
}