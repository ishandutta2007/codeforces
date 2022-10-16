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

const int maxn = 312345;

ll d[maxn], c[maxn], a, ans;
int n;

int main() {
    scanf("%d%lld", &n, &a);
    FOR(i, 1, n) {
        scanf("%lld%lld", d + i, c + i);
        c[i] = a - c[i];
        ans = max(ans, c[i]);
        c[i] += c[i - 1];
    }
    vector<pair<ll, ll>> lis;
    lis.eb(1e9 + 123, min(c[0], c[1]));
    FOR(i, 2, n) {
        while (!lis.empty() && lis.back()._1 <= d[i] - d[i - 1]) lis.pop_back();
        lis.eb(d[i] - d[i - 1], c[i - 1]);
        REP(j, int(lis.size()) - 1) {
            lis[j]._2 = min(lis[j]._2, c[i - 1]);
            ans = max(ans, c[i] - lis[j]._2 - sqr(lis[j + 1]._1));
        }
    }
    printf("%lld", ans);
}