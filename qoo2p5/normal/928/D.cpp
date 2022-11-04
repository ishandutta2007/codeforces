
#include <bits/stdc++.h>
using namespace std;

#define f(_i, _n) for (auto _i = 0; _i < _n; _i++)
#define F(_i, _k, _n) for (auto _i = _k; _i < _n; _i++)
#define re return
#define pb push_back
#define all(_v) _v.begin(), _v.end()
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }
#define fi first
#define se second

typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

map<char, int> nxt[300500];

bool ee[300500];
int cnt[300500];

int economy(string s) {
  int cur = 0;
  int ans = 0;
  int ok = 0;
  bool started = 0;
  f(i, (int)s.size()) {
    if (!nxt[cur].count(s[i])) {
      break;
    }
    cur = nxt[cur][s[i]];
    if (ee[cur] && started) {
      ok = 1;
    }
    if (cnt[cur] == 1) {
      ans++;
      started = true;
      // cerr << s << ' ' << i << '\n';
    }
  }
  if (!ok) {
    re 0;
  }
  re max(ans - 2, 0);
}

bool find(string s) {
  int cur = 0;
  f(i, (int)s.size()) {
    if (!nxt[cur].count(s[i])) {
      re 0;
    }
    cur = nxt[cur][s[i]];
  }
  re ee[cur];
}

int sz = 1;

void add(string s) {
  int cur = 0;
  // cerr << s << "\n ";
  f(i, (int)s.size()) {
    if (!nxt[cur].count(s[i])) {
      nxt[cur][s[i]] = sz++;
    }
    cur = nxt[cur][s[i]];
    cnt[cur]++;
  }
  ee[cur] = 1;
}

int ans = 0;

void solve(string s) {
  ans -= economy(s);
  // cerr << '\n';
  // if (economy(s) > 0) cerr << s << ' ' << find(s) << ' ' << economy(s) << '\n';
  if (!find(s)) {
    add(s);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  cnt[0] = 10;
  int sz = 0;

  while (getline(cin, s)) {
    string cur;
    sz += s.size() + 1;
    f(i, (int)s.size()) {
      if ('a' <= s[i] && s[i] <= 'z') {
        cur += s[i];
      } else {
        if (!cur.empty()) {
          solve(cur);
          cur = "";
        }
      }
      ans++;
    }
    if (cur != "") {
      solve(cur);
    }
    ans++;
  }
  cout << ans;
}