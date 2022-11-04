
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

set<string> login;

string parse(string t) {
  f(i, (int)t.size()) {
    if ('A' <= t[i] && t[i] <= 'Z') {
      t[i] -= 'A';
      t[i] += 'a';
    }
    if (t[i] == '0') {
      t[i] = 'o';
    }
    if (t[i] == '1') {
      t[i] = 'l';
    }
    if (t[i] == 'i') {
      t[i] = 'l';
    }
  }
  re t;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  s = parse(s);
  int n;
  cin >> n;
  f(i, n) {
    string t;
    cin >> t;
    t = parse(t);
    login.insert(t);
  }
  cout << (login.count(s) ? "No" : "Yes");
}