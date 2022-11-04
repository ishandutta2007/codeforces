
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

map<pair<string, int>, vector<pair<string, int> > > gr;

map<string, int> version;

queue<string> q;

map<string, int> was;
vector<pair<string, int> > ans;

map<string, int> d;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  f(i, n) {
    string name;
    int v;
    cin >> name >> v;
    if (i == 0) {
      q.push(name);
      version[name] = v;
      was[name] = 1;
    }
    int cnt;
    cin >> cnt;
    f(j, cnt) {
      string name2;
      int v2;
      cin >> name2 >> v2;
      // cerr << "(" << name << ", " << v << ") -> (" << name2 << ' ' << v2 << ")\n";
      gr[{name, v}].push_back({name2, v2});
    }
  }

  int it = 0;

  while (!q.empty()) {
    string cur = q.front();
    q.pop();

    pair<string, int> v = {cur, version[cur]};
    // cerr << cur << ' ' << version[cur] << '\n';

    if (it != 0) {
      ans.pb(v);
    }
    it++;

    for (auto to : gr[v]) {
      // cerr << ' ' << to.fi << '\n';
      if (was[to.fi] != 2) {
        if (was[to.fi] == 0) {
          was[to.fi] = 1;
          q.push(to.fi);
          version[to.fi] = to.se;
          d[to.fi] = d[cur] + 1;
        } else if (d[to.fi] == d[cur] + 1) {
          version[to.fi] = max(to.se, version[to.fi]);
        }
      }
    }
  }

  sort(all(ans));

  cout << ans.size() << '\n';

  for (auto x : ans) {
    cout << x.fi << ' ' << x.se << '\n';
  }
}