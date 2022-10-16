#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 112345;

ordered_set<int> in[maxn], out[maxn];
map<int, int> rec;
int n, a, t, x, cnt;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d%d", &a, &t, &x);
    if (!rec.count(x)) rec[x] = cnt++;
    int idx = rec[x];
    if (a == 1) in[idx].insert(t);
    else if (a == 2) out[idx].insert(t);
    else printf("%d\n", int(in[idx].order_of_key(t) - out[idx].order_of_key(t)));
  }
}