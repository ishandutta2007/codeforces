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

const int maxn = (1 << 18) + 123;

int n, r, c[maxn];
ll ans;

int main() {
    scanf("%d%d", &n, &r);
    REP(i, 1 << n) {
        scanf("%d", &c[i]);
        ans += c[i];
    }
    double den = 1 << n;
    printf("%.10lf\n", ans / den);
    REP(i, r) {
        int z;
        scanf("%d", &z);
        ans -= c[z];
        scanf("%d", &c[z]);
        ans += c[z];
        printf("%.10lf\n", ans / den);
    }
    return 0;
}