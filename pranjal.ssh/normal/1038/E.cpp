#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

struct DSU {
  vi p, r;
  DSU(int n):p(n),r(n){FOR(i, 0, n - 1)p[i] = i;}

  int get(int i) {
    if (p[i] != i)p[i] = get(p[i]);
    return p[i];
  }
  int connect(int i, int j) {
    int x = get(i), y = get(j);
    if (x == y) return 0;
    if (r[x] > r[y]) swap(x, y);
    p[x] = y;
    if (r[x] == r[y]) ++r[y];
    return 1;
  }
};
int solve(int mask, vi g[4][4]) {
  int ans = 0, odd = 0;
  FOR (i, 0, 3) if (mask & (1 << i)) {
    ans += accumulate(all(g[i][i]), 0);
    int no = 0;
    FOR (j, 0, 3) if (mask & (1 << j)) if (i != j) {
      if (j > i)
        ans += accumulate(all(g[i][j]), 0);
      no += g[i][j].size();
    }
    odd += no % 2;
  }
  
  assert(odd % 2 == 0);

  return odd > 2 ? 0 : ans;
}
int solve(vi g[4][4]) {
  DSU ds(4);
  FOR (i, 0, 3) FOR (j, 0, 3) if (g[i][j].size()) ds.connect(i, j);
  vi yo(4);
  FOR (i, 0, 3) yo[ds.get(i)] |= (1 << i);
  int ans = 0;
  FOR (i, 0, 3) if (yo[i]) {
    ans = max(ans, solve(yo[i], g));
  }
  return ans;
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vi g[4][4];
  FOR (i, 0, n - 1) {
    int x, y, val; cin >> x >> val >> y;
    --x, --y;
    g[x][y].push_back(val);
    if (x != y)
      g[y][x].push_back(val);
  }
  
  FOR (i, 0, 3) FOR (j, 0, 3) sort(all(g[i][j])), reverse(all(g[i][j]));
  int ans = solve(g);

  FOR (mask, 0, 15) {
    vi x;
    FOR (i, 0, 3) if (mask & (1 << i)) x.push_back(i);
    if (sz(x) <= 1) continue;
    do {
      
      bool can = true;
      FOR (i, 0, sz(x)-2) {
        can &= !g[x[i]][x[i+1]].empty();
      }
      if (can) {
        map<ii, int> mp;
        FOR (i, 0, sz(x)-2) {
          mp[{x[i],x[i+1]}] = g[x[i]][x[i+1]].back();
          mp[{x[i+1],x[i]}] = g[x[i+1]][x[i]].back();
          assert(g[x[i+1]][x[i]].back() == g[x[i]][x[i+1]].back());
          g[x[i]][x[i+1]].pop_back();
          g[x[i+1]][x[i]].pop_back();
        }
        ans = max(ans, solve(g));
        for (auto it : mp) g[it.F.F][it.F.S].push_back(it.S);
      }
    } while (next_permutation(all(x)));
  }
  cout << ans;

  return 0;
}