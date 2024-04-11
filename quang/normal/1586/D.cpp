#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> nxt(n, -1);
  vector<int> used(n, 0);
  
  // mt19937 rng(0);
  // vector<int> val(n);
  // iota(val.begin(), val.end(), 1);
  // shuffle(val.begin(), val.end(), rng);

  // // debug(val);

  auto Ask = [&](const vector<int> &a) {
    cout << "?";
    for (auto u : a) {
      cout << ' ' << u;
    }
    cout << endl;

    int k;
    cin >> k;
    k--;
    return k;


    // map<int, int> m;
    // for (int i = 0; i < n; i++) {
    //   auto now = a[i] + val[i];
    //   if (m.count(now)) return m[now];
    //   m[now] = i;
    // }
    // return -1;
  };

  vector<int> a(n, 1);

  for (int i = 0; i < n; i++) {
    a[i] = 2;
    auto k = Ask(a);
    a[i] = 1;
    assert(k <= i);
    if (k == -1 || k == i) continue;
    // debug(i, k);
    nxt[i] = k;
    used[k] = 1;
  }

  vector<int> b(n, 2);

  for (int i = 0; i < n; i++) {
    b[i] = 1;
    auto k = Ask(b);
    b[i] = 2;
    assert(k <= i);
    if (k == -1 || k == i) continue;
    nxt[k] = i;
    // debug(k, i);
    used[i] = 1;
  }

  int root = -1;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      root = i;
      break;
    }
  }
  assert(root != -1);

  // debug(nxt);
  // debug(used);
  // debug(root);

  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    assert(root != -1);
    res[root] = i + 1;
    root = nxt[root];
  }
  cout << "!";
  // debug(res);
  for (auto u : res) cout << ' ' << u ;
  cout << endl;
  // cout << endl;
  // assert(res == val);
  return 0;
}