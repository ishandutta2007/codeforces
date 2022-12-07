#include <bits/stdc++.h>

using namespace std;

const int N = 500030;
const int mod = 1e9 + 7;

struct SegmentTree{
  int T[N << 2];
  int lazy[N << 3];

  #define mid ((l + r) >> 1)

  void toggle(int v, int l, int r){
    if(lazy[v] == -1) return;
    T[v] = (1LL * lazy[v] * (r - l + 1) % mod);
    lazy[v + v] = lazy[v];
    lazy[v + v + 1] = lazy[v];
    lazy[v] = -1;
  }

  void modify(int x, int l, int r, int u, int v, int val){
    toggle(x, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
      lazy[x] = val;
      toggle(x, l, r);
      return;
    }
    modify(x + x, l, mid, u, v, val);
    modify(x + x + 1, mid + 1, r, u, v, val);
    T[x] = (T[x + x] + T[x + x + 1]);
    if(T[x] >= mod) T[x] -= mod;
  }

  int query(int x, int l, int r, int u, int v) {
    toggle(x, l, r);
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return T[x];
    int ret = query(x + x, l, mid, u, v) + query(x + x + 1, mid + 1, r, u, v);
    if(ret >= mod) ret -= mod;
    T[x] = T[x + x] + T[x + x + 1];
    if(T[x] >= mod) T[x] -= mod;
    return ret;
  }
};

SegmentTree f[2];

int fpow(int x, int y) {
  int ret = 1;
  while(y){
    if(y & 1) ret = (1LL * ret * x) % mod;
    x = (1LL * x * x) % mod;
    y >>= 1;
  }
  return ret;
}

int L, n, m;
vector < int > req[2][N];
pair < int, int > a[N], b[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);


  cin >> L >> n >> m;

  vector < int > vals = {0, L};

  for(int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    vals.push_back(a[i].first - 1);
    vals.push_back(a[i].second);
  }

  for(int i = 1; i <= m; ++i) {
    cin >> b[i].first >> b[i].second;
    vals.push_back(b[i].first - 1);
    vals.push_back(b[i].second);
  }

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  for(int i = 1; i <= n; ++i) {
    a[i].first = lower_bound(vals.begin(), vals.end(), a[i].first) - vals.begin();
    a[i].second = lower_bound(vals.begin(), vals.end(), a[i].second) - vals.begin();
    req[0][a[i].second].push_back(a[i].first);
  }

  for(int i = 1; i <= m; ++i){
    b[i].first = lower_bound(vals.begin(), vals.end(), b[i].first) - vals.begin();
    b[i].second = lower_bound(vals.begin(), vals.end(), b[i].second) - vals.begin();
    req[1][b[i].second].push_back(b[i].first);
  }

  /// f[0][i] represents the number of way to have the last segment all flipped up and the last flipdown is i
  /// f[1][i]

  long long all = 1;
  for(int i = 1; i < vals.size(); ++i){
    /// set this segment all flip up
    long long wup = f[1].T[1] + all; wup %= mod;
    /// flip down
    long long wdown = f[0].T[1] + all; wdown %= mod;

    /// Both up and down
    all = (all + f[0].T[1] + f[1].T[1]) % mod;
    all = (all * (fpow(2, vals[i] - vals[i - 1]) - 2)) % mod;


    f[0].modify(1, 0, vals.size(), i - 1, i - 1, wup);
    f[1].modify(1, 0, vals.size(), i - 1, i - 1, wdown);

    for(auto &r : req[0][i]) {
      f[0].modify(1, 0, vals.size(), 0, r - 1, 0);
    }
    for(auto &r : req[1][i]) {
      f[1].modify(1, 0, vals.size(), 0, r - 1, 0);
    }

  }

  cout << (all + f[0].T[1] + f[1].T[1]) % mod << endl;

  return 0;
}