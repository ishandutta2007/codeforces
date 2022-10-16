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

const int maxn = 123;

int n, a[maxn * 2], ans;

int main() {
    scanf("%d", &n);
    REP(i, 2 * n) scanf("%d", &a[i]);
    REP(i, n) {
        if (a[2 * i] != a[2 * i + 1]) {
            FOR(j, 2 * i + 2, 2 * n - 1) {
                swap(a[j], a[2 * i + 1]);
                ans++;
                if (a[2 * i] == a[2 * i + 1]) break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}