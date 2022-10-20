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

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> res;
  int pos = 0;
  while (pos + 2 < n) {
    if (a[pos] == 0) {
      pos++;
      continue;
    }
    if (a[pos + 1] == 0 && a[pos + 2] == 0) {
      res.push_back(pos);
      a[pos + 1] = a[pos + 2] = 1;
      pos += 2;
      continue;
    } 
    if (a[pos + 1] == 1 && a[pos + 2] == 1) {
      pos += 2;
      continue;
    }
    pos += 3;
  }
  debug(a);
  pos = 0;
  while (pos + 2 < n) {
    if (a[pos] == 0) {
      if (a[pos + 1] == 1 && a[pos + 2] == 1) {
        res.push_back(pos);
        a[pos + 1] = a[pos + 2] = 0;
        pos += 2;
        continue;
      }
      pos++;
    } else {
      if (a[pos + 1] == 0 && a[pos + 2] == 0) {
        cout << "NO\n";
        return;
      }
      if (a[pos + 1] == 1 && a[pos + 2] == 1) {
        pos += 2;
        continue;
      }
      res.push_back(pos);
      a[pos] = a[pos + 1] = a[pos + 2] = 0;
      pos -= 2;
      int u = pos;
      while (u >= 0 && a[u] == 1 && a[u + 1] == 1) {
        a[u] = a[u + 1] = 0;
        res.push_back(u);
        u -= 2;
      }
      pos += 2;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  cout << res.size() << '\n';
  for (auto u : res) {
    cout << u + 1 << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}