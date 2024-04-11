#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234;

int n;
ll a[maxn], d[maxn];

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld", a + i);
    FOR(i, 1, n) d[i] = a[i] - a[i - 1];
    vector<int> ans;
    FOR(k, 1, n) {
        bool ok = true;
        FOR(i, 1, k) {
            for (int j = 1; i + k * j <= n; j++) {
                if (d[i] != d[i + k * j]) {
                    ok = false;
                    goto label;
                }
            }
        }
        label:;
        if (ok) ans.pb(k);
    }
    printf("%d\n", int(ans.size()));
    for (auto it : ans) printf("%d ", it);
}