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

const int N = 100010;

int n;
string s;
int num[30];

void solve(int test) {
  fill(num, num + 26, 0);
  cin >> s;
  n = s.size();
  for (auto u : s) {
    num[u - 'a']++;
  }
  int num1 = -1;
  for (int i = 0; i < 26; i++) {
    if (num[i] == 1) {
      num1 = i;
      break;
    }
  }
  if (num1 != -1) {
    cout << (char)(num1 + 'a');
    num[num1]--;
    for (int i = 0; i < 26; i++) {
      while (num[i]--) {
        cout << (char)(i + 'a');
      }
    }
    cout << '\n';
    return;
  }
  bool all = 1;
  for (int i = 0; i < 26; i++) {
    if (num[i] > 0 && num[i] < n) {
      all = 0;
      break;
    }
  }
  if (all) {
    cout << s << '\n';
    return;
  }
  int u = -1, v = -1;
  for (int i = 0; i < 26 && u == -1; i++) {
    if (!num[i]) continue;
    for (int j = 0; j < 26 && u == -1; j++) {
      if (!num[j]) continue;
      if (i == j) {
        if (num[i] <= (n + 2) / 2) {
          u = v = i;
          break;
        }
      } else {
        u = i;
        v = j;
        break;
      }
    }
  }
  assert(u != -1);
  if (u == v) {
    string res = "";
    res += (char)(u + 'a');
    res += (char)(u + 'a');
    num[u] -= 2;
    int lastU = 1;
    int tot = n - 2;
    for (int it = 3; it <= n; it++) {
      int found = -1;
      for (int i = 0; i < 26; i++) {
        if (!num[i]) continue;
        if (lastU && i == u) continue;
        if (i == u && num[u] - 1 <= tot - num[u]) {
          found = i;
          break;
        }
        if (i != u && num[u] <= tot - num[u]) {
          found = i;
          break;
        }
      }
      assert(found != -1);
      tot--;
      lastU = u == found;
      res += (char)(found + 'a');
      num[found]--;
    }
    cout << res << '\n';
    return;
  }
  string res = "";
  res += (char)(u + 'a');
  res += (char)(v + 'a');
  num[u]--;
  num[v]--;
  int lastU = 0;
  int tot = n - 2;
  for (int it = 3; it <= n; it++) {
    int found = -1;
    for (int i = 0; i < 26; i++) {
      if (!num[i]) continue;
      if (lastU && i == v) continue;
      if (i == u && (num[v] == 0 || num[u] - 1 + num[v] < tot - 1)) {
        found = i;
        break;
      }
      if (i != u) {
        found = i;
        break;
      }
    }
    assert(found != -1);
    tot--;
    lastU = u == found;
    res += (char)(found + 'a');
    num[found]--;
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