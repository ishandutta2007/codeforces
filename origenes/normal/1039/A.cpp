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

const int maxn = 212345;

ll a[maxn], b[maxn], t;
int x[maxn], cnt[maxn];
int n;

int main() {
    scanf("%d%lld", &n, &t);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        b[i] = a[i] + t;
    }
    FOR(i, 1, n) {
        scanf("%d", &x[i]);
        if (x[i] < i) {
            puts("No");
            return 0;
        }
        cnt[i]++;
        cnt[x[i]]--;
    }
    int now = 0;
    FOR(i, 1, n) {
        if (now += cnt[i]) b[i] = max(b[i], a[i + 1] + t);
        b[i] = max(b[i], b[i - 1] + 1);
    }
    FOR(i, 1, n) if (x[i] < n && b[x[i]] >= a[x[i] + 1] + t) {
            puts("No");
            return 0;
        }
    puts("Yes");
    FOR(i, 1, n) printf("%lld ", b[i]);
    puts("");
    return 0;
}