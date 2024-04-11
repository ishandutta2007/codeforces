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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;
const int inf = 0x3f3f3f3f;

int n, q, a[maxn], L[maxn], R[maxn], p[maxn], ans[maxn];

int query(int x) {
    return p[x] ? p[x] = query(p[x]) : x;
}

int main() {
    scanf("%d%d", &n, &q);
    reset(L, 0x3f);
    L[1] = 1;
    int lst = -1;
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        if (L[a[i]] == inf) L[a[i]] = i;
        R[a[i]] = i;
        if (!a[i]) lst = i;
    }
    R[1] = n;
    ROF(i, q, 1) {
        if (L[i] == inf) {
            if (lst != -1) L[i] = R[i] = lst;
            else {
                puts("NO");
                return 0;
            }
        } else lst = L[i];
    }
    ROF(i, q, 1) for (int j = query(L[i]); j <= R[i]; j = query(j)) {
            ans[j] = i;
            p[j] = j + 1;
        }
    FOR(i, 1, n) if (a[i] && ans[i] != a[i]) {
            puts("NO");
            return 0;
        }
    puts("YES");
    FOR(i, 1, n) printf("%d ", ans[i]);
    puts("");
    return 0;
}