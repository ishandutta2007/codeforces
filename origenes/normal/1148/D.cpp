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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

struct Seg {
  int a, b, id;

  Seg (int a, int b, int id) : a(a), b(b), id(id) {}
};

int n, a, b;

int main() {
  scanf("%d", &n);
  vector<Seg> v1, v2;
  FOR(i, 1, n) {
    scanf("%d%d", &a, &b);
    if (a < b) v1.eb(a, b, i);
    else v2.eb(a, b, i);
  }
  sort(all(v1), [&](const Seg &x, const Seg &y) { return x.b > y.b; });
  sort(all(v2), [&](const Seg &x, const Seg &y) { return x.b < y.b; });
  const auto &v = v1.size() > v2.size() ? v1 : v2;
  printf("%d\n", int(v.size()));
  for (auto it : v) printf("%d ", it.id);
}