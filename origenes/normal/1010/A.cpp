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

const int maxn = 1234;

int n, m, a[maxn], b[maxn], coeff[2 * maxn];
double f;


int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            puts("-1");
            return 0;
        }
    }
    FOR(i, 1, n) {
        scanf("%d", &b[i]);
        if (b[i] == 1) {
            puts("-1");
            return 0;
        }
    }
    coeff[0] = b[1];
    FOR(i, 1, n - 1) {
        coeff[i * 2 - 1] = a[n - i + 1];
        coeff[i * 2] = b[n - i + 1];
    }
    coeff[2 * n - 1] = a[1];
    f = m;
    REP(i, 2 * n)
        f = f / (coeff[i] - 1) + f;
    printf("%.10lf\n", f - m);
    return 0;
}