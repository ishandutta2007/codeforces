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

const int maxn = 212345;

int n, m, k;
ll a[maxn];
bool vis[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, n) scanf("%lld", a + i);
    set<pair<ll, int>> s;
    FOR(i, 1, n) {
        s.insert(mp(a[i], i));
        if (s.size() > m * k) s.erase(s.begin());
    }
    for (const auto &it : s) vis[it._2] = true;
    int cnt = 0;
    vector<int> ans;
    ll ret = 0;
    FOR(i, 1, n) if (vis[i]) {
            cnt++;
            ret += a[i];
            if (cnt == m) {
                ans.eb(i);
                cnt = 0;
            }
        }
    printf("%lld\n", ret);
    REP(i, int(ans.size()) - 1) printf("%d ", ans[i]);
}