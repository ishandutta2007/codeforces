#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

struct Seg {
  ll off;
  map<int, ll> cost;
  map<ll, int> cnt;

  Seg(int y, ll v) {
    off = 0;
    cost.clear();
    cnt.clear();
    cost[y] = v;
    cnt[v] = 1;
  }

  ll query(int y) {
    if (!cost.count(y)) return 1e15;
    return cost[y] + off;
  }

  ll min() {
    return cnt.begin()->_1 + off;
  }

  void erase(int y) {
    if (cost.count(y)) {
      ll v = cost[y];
      cost.erase(y);
      if (!--cnt[v]) cnt.erase(v);
    }
  }

  void update(int y, ll v) {
    ll pc = query(y);
    if (v < pc) {
      erase(y);
      cost[y] = v - off;
      cnt[v - off]++;
    }
  }
};

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, s;
  cin >> n >> s;
  vector<Seg> S;
  stack<int> cond;
  S.eb(0, 0);
  REP(i, n) {
    string op; cin >> op;
    if (op == "set") {
      auto &seg = S.back();
      int y, v;
      cin >> y >> v;
      if (y != s) seg.update(y, seg.min() - v);
      seg.off += v;
    } else if (op == "if") {
      int y; cin >> y;
      cond.emplace(y);
      auto &seg = S.back();
      ll ini = seg.query(y);
      S.eb(y, ini);
    } else {
      int y = cond.top(); cond.pop();
      S[S.size() - 2].erase(y);
      if (S[S.size() - 2].cost.size() < S.back().cost.size()) swap(S[S.size() - 2], S.back());
      for (auto [y, v] : S.back().cost) if (S[S.size() - 2].query(y) > v + S.back().off)
        S[S.size() - 2].update(y, v + S.back().off);
      S.pop_back();
    }
  }
  cout << S.back().min();
}