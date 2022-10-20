#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N> string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res; }
template <typename A> string to_string(A v) {
  bool first = true; string res = "{";
  for (const auto &x : v)
    {if (!first) res += ", "; first = false; res += to_string(x);}
  res += "}"; return res; }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << " " << to_string(H);debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void solve(int test) {
  int n, k;
  cin >> n >> k;
  vector<int> used(n * 2, 0);
  vector<pair<int, int>> chords;
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    chords.push_back({u, v});
    used[u] = used[v] = 1;
  }
  vector<int> ls;
  for (int i = 0; i < n * 2; i++) {
    if (!used[i]) ls.push_back(i);
  }
  int m = ls.size();
  assert(m % 2 == 0);
  for (int i = 0; i < m / 2; i++) {
    chords.push_back({ls[i], ls[i + m / 2]});
  }
  int res = 0;
  sort(chords.begin(), chords.end());
  // debug(chords);
  for (int i = 0; i < chords.size(); i++) {
    for (int j = i + 1; j < chords.size(); j++) {
      res += chords[j].first < chords[i].second && chords[i].second < chords[j].second;
    }
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}