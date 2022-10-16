#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123456;

char s[maxn];
int n, m;
int match[maxn], l[maxn], r[maxn], ans[maxn];
vector<int> q[maxn];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  stack<int> L;
  FOR(i, 1, n) {
    if (s[i] == '(') L.emplace(i);
    else if (!L.empty()) {
      match[i] = L.top();
      L.pop();
    }
  }
  scanf("%d", &m);
  FOR(i, 1, m) {
    scanf("%d%d", l + i, r + i);
    q[r[i]].eb(i);
  }
  ordered_set<int> S;
  FOR(i, 1, n) {
    if (match[i]) S.insert(match[i]);
    for (auto j : q[i]) ans[j] = int(S.size()) - S.order_of_key(l[j]);
  }
  FOR(i, 1, m) printf("%d\n", 2 * ans[i]);
}