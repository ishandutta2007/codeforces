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

const int maxn = 112345;

int a[maxn], n, k, m;
ll s[maxn];

int main() {
    scanf("%d%d%d", &n, &k, &m);
    FOR(i, 1, n) scanf("%d", a + i);
    sort(a + 1, a + n + 1, greater<int>());
    FOR(i, 1, n) s[i] = s[i - 1] + a[i];
    pair<ll, int> ans = mp(0LL, 1);
    ROF(i, n, 1) {
        int used = n - i, rem = m - used;
        if (rem < 0) break;
        ll cur = min(ll(i) * k, ll(rem)) + s[i];
        if (ans._1 * i < cur * ans._2) ans = mp(cur, i);
    }
    printf("%.10lf", double(ans._1) / ans._2);
}