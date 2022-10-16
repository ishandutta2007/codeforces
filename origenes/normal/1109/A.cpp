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
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 312345;

int n, a[maxn], s[maxn];

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        s[i] = s[i - 1] ^ a[i];
    }
    unordered_map<int, int> pre[2];
    ll ans = 0;
    pre[0][0] = 1;
    FOR(i, 1, n) {
        int j = i & 1;
        ans += pre[j][s[i]];
        pre[j][s[i]]++;
    }
    printf("%lld", ans);
}