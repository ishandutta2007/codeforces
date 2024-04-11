#include <bits/stdc++.h>

using namespace std;

// source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
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

const int N = 200010;

int n;
int a[N];
int used[N];
int deg[N];

void solve(int test) {
  cin >> n;
  fill(used + 1, used + n + 1, 0);
  fill(deg + 1, deg + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    deg[a[i]]++;
  }
  vector<int> head, tail;
  for (int i = 1; i <= n; i++) {
    if (!deg[i]) {
      int u = i;
      head.push_back(u);
      queue<int> q;
      while (1) {
        used[u] = 1;
        if (!used[a[u]]) u = a[u];
        else break;
      }
      tail.push_back(u);
    }
  }

  // debug(head, tail);

  int res = n - head.size();
  cout << res << '\n';
  for (int i = 0; i < head.size(); i++) {
    a[tail[i]] = head[(i + 1) % (int)head.size()];
  } 
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}