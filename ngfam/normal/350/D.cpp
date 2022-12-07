#include<bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
  if(x == 0) return y;
  if(y == 0) return x;
  return __gcd(x, y);
}

struct Line{
  /// ax + by + c = 0
  int a, b, c;
  void normalize() {
    long long g = gcd(gcd(a, b), c);
    if(g != 0){
      a /= g;
      b /= g;
      c /= g;
    }
    if(a < 0) {
      a *= -1;
      b *= -1;
      c *= -1;
    }
  }

  bool operator <(const Line &rhs) const{
    if(a != rhs.a) return a < rhs.a;
    if(b != rhs.b) return b < rhs.b;
    return c < rhs.c;
  }

  bool operator ==(const Line &rhs) const{
    return a == rhs.a && b == rhs.b && c == rhs.c;
  }
};

using Point = pair<int, int>;

const int MAXN = 2002;

int x[MAXN], y[MAXN], r[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<array<int, 4>> a(n);

  vector<Line> seg, b(n);

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 4; ++j) cin >> a[i][j], a[i][j] *= 2;
    if(make_pair(a[i][0], a[i][1]) > make_pair(a[i][2], a[i][3])) {
      swap(a[i][0], a[i][2]);
      swap(a[i][1], a[i][3]);
    }
    int x = a[i][3] - a[i][1];
    int y = a[i][0] - a[i][2];
    int z = 1LL * a[i][1] * (a[i][2] - a[i][0]) - 1LL * a[i][0] * (a[i][3] - a[i][1]);

    seg.push_back(b[i] = {x, y, z});
    seg.back().normalize();
    b[i].normalize();
  }

  sort(seg.begin(), seg.end());
  seg.erase(unique(seg.begin(), seg.end()), seg.end());

  vector<int> cnt(seg.size());
  vector<vector<pair<Point, int>>> f(seg.size());
  for(int i = 0; i < n; ++i) {
    Line cur = b[i];
    auto fpos = lower_bound(seg.begin(), seg.end(), cur) - seg.begin();
    ++cnt[fpos];
    f[fpos].emplace_back(make_pair(a[i][0], a[i][1]), -(i + 1));
    f[fpos].emplace_back(make_pair(a[i][2], a[i][3]), i + 1);
  }

  for(int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i] >> r[i];
    x[i] *= 2;
    y[i] *= 2;
    r[i] *= 2;
  }

  for(int i = 0; i < m; ++i) {
    for(int j = i + 1; j < m; ++j) if(r[i] == r[j]){
      int midx = (x[i] + x[j]) / 2, midy = (y[i] + y[j]) / 2;
      int dx = midx - x[i], dy = midy - y[i];
      if(dx * dx + dy * dy <= r[i] * r[i]) continue;
      int subx = (x[j] - x[i]), suby = (y[j] - y[i]);
      /// subx * (x - midx) + suby * (y - midy) = 0
      int x = subx, y = suby, z = -subx * midx - suby * midy;
      Line cur = {x, y, z};
      cur.normalize();

      auto fpos = lower_bound(seg.begin(), seg.end(), cur) - seg.begin();
      if(fpos < seg.size() && seg[fpos] == cur)
        f[fpos].emplace_back(make_pair(midx, midy), 0);
    }
  }

  int ans = 0;

  for(auto &vec : f) {
    sort(vec.begin(), vec.end());

    int cur = 0;
    for(int i = 0; i < vec.size(); ++i) {
      int j = i;
      while(j < vec.size() && vec[j].first == vec[i].first) {
        if(vec[j].second < 0) ans -= cur;
        else if(vec[j].second == 0) ++cur;
        else ans += cur;
        ++j;
      }
      i = j - 1;
    }
  }

  cout << ans << endl;

  return 0;
}