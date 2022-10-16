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

const int maxn = 1234567;
const ll MOD = 998244353;

int a[maxn], n, fac[maxn], ans;

int mul(int a, int b) {
    return ll(a) * b % MOD;
}

int add(int a, int b) {
    return ((a + b) % MOD + MOD) % MOD;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    fac[0] = 1;
    FOR(i, 1, n - 1) fac[i] = mul(fac[i - 1], 2);
    int diff = mul(fac[n - 1], a[0]);
    REP(i, n) {
        ans = add(ans, diff);
        if (i != n - 1) {
            diff = add(diff, -mul(fac[n - 2 - i], a[i]));
            diff = add(diff, mul(fac[n - 2 - i], a[i + 1]));
        }
    }
    printf("%d\n", ans);
    return 0;
}