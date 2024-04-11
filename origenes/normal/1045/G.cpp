#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

const int maxn = 112345;

int x[maxn], r[maxn], q[maxn], id[maxn];
int n, k;

ordered_set<pii> s[maxn];

//    ordered_set<int> s;
//    s.insert(1);
//    s.insert(3);
//    cout << s.order_of_key(2) << endl;
//    cout << *s.find_by_order(0) << endl;

int main() {
    scanf("%d%d", &n, &k);
    vector<int> lis;
    FOR(i, 1, n) {
        scanf("%d%d%d", x + i, r + i, q + i);
        id[i] = i;
        lis.eb(q[i]);
    }
    sort(all(lis));
    uni(lis);
    sort(id + 1, id + n + 1, [](int a, int b) { return r[a] > r[b]; });
    ll ans = 0;
    FOR(i, 1, n) {
        auto now = lower_bound(all(lis), q[id[i]]) - lis.begin();
        ROF(cur, now, 0) {
            if (lis[cur] + k < lis[now]) break;
            ans += s[cur].order_of_key(mp(x[id[i]] + r[id[i]] + 1, -1)) - s[cur].order_of_key(mp(x[id[i]] - r[id[i]] - 1, int(1e9)));
        }
        FOR(cur, now + 1, int(lis.size()) - 1) {
            if (lis[cur] - k > lis[now]) break;
            ans += s[cur].order_of_key(mp(x[id[i]] + r[id[i]] + 1, -1)) - s[cur].order_of_key(mp(x[id[i]] - r[id[i]] - 1, int(1e9)));
        }
        s[now].insert(mp(x[id[i]], i));
    }
    printf("%lld", ans);
}