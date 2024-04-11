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
const int maxn = 123456;
int n, m, phi[maxn];
ll tot;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

bool phi_table() {
    phi[1] = 1;
    FOR(i, 2, n) if (!phi[i])
            for (int j = i; j <= n; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    FOR(i, 2, n) tot += phi[i];
    return tot >= m;
}

int main() {
    scanf("%d%d", &n, &m);
    if (!phi_table() || m + 1 < n) {
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            if (gcd(i, j) == 1) {
                printf("%d %d\n", i, j);
                m--;
                if (!m) return 0;
            }
        }
    }
    return 0;
}