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

const int maxn = 512345;

int n, c, ans;
int a[maxn], s[2][maxn], ss[maxn], last[maxn];

int main() {
    scanf("%d%d", &n, &c);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        s[0][i] = s[0][i - 1] + (a[i] == c);
    }
    ROF(i, n, 1) s[1][i] = s[1][i + 1] + (a[i] == c);
    FOR(i, 1, n) {
        ss[i] = s[0][i - 1] + 1;
        int lst = last[a[i]];
        if (lst > 0) ss[i] = max(ss[i], ss[lst] + 1);
        last[a[i]] = i;
    }
    FOR(i, 1, n) ans = max(ans, ss[i] + s[1][i + 1]);
    printf("%d\n", ans);
}