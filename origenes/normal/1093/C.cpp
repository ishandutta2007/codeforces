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

int n;
ll b, a[2][maxn];

int main() {
    scanf("%d", &n);
    n >>= 1;
    a[1][0] = 2e18;
    FOR(i, 1, n) {
        scanf("%lld", &b);
        a[0][i] = a[0][i - 1];
        a[1][i] = a[1][i - 1];
        ll s = a[0][i] + a[1][i];
        if (s > b) a[1][i] -= s - b;
        else if (s < b) a[0][i] += b - s;
    }
    FOR(i, 1, n) printf("%lld ", a[0][i]);
    ROF(i, n, 1) printf("%lld ", a[1][i]);
}