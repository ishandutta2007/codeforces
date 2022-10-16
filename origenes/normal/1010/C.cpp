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

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int n, k, a;

int main() {
    scanf("%d%d", &n, &k);
    int now = k;
    FOR(i, 1, n) {
        scanf("%d", &a);
        now = gcd(a, now);
        if (now == 1) break;
    }
    printf("%d\n", k / now);
    REP(i, k / now)
        printf("%d ", i * now);
    puts("");
    return 0;
}