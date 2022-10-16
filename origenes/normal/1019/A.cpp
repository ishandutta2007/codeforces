#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 3123;

int n, m;
vector<int> p[maxn];
ll ans = 1e18;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int pp, c;
        scanf("%d%d", &pp, &c);
        p[pp - 1].pb(c);
    }
    REP(i, m) sort(all(p[i]));
    FOR(v, 1, n) {
        ll cost = 0;
        int diff = v - p[0].size();
        vector<int> rem;
        FOR(i, 1, m - 1) {
            int idx = max(int(p[i].size()) - v + 1, 0);
            REP(j, idx) {
                cost += p[i][j];
                diff--;
            }
            FOR(j, idx, int(p[i].size()) - 1) rem.pb(p[i][j]);
        }
        if (diff > 0) {
            nth_element(rem.begin(), rem.begin() + diff, rem.end());
            REP(i, diff) cost += rem[i];
        }
        ans = min(ans, cost);
    }
    printf("%lld\n", ans);
    return 0;
}