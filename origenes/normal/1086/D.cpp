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

const int maxn = 212345;

int n, C[3][maxn], q;
set<int> s[3];
char ini[maxn], op[5];

inline int lowbit(int x) {
    return x & -x;
}

int sum(const int *C, int x) {
    int ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int *C, int x, int d) {
    while (x <= n) {
        C[x] += d;
        x += lowbit(x);
    }
}

int query() {
    int cnt = 0;
    REP(i, 3) cnt += s[i].empty();
    if (cnt == 2) return n;
    if (cnt == 1) REP(i, 3)
            if (s[i].size() && s[(i + 2) % 3].size()) return s[i].size();
    int ans = n;
    REP(i, 3) {
        int l = *(s[(i + 1) % 3].begin()), r = *(s[(i + 2) % 3].begin());
        if (r > l) ans -= sum(C[i], r) - sum(C[i], l);
        l = *(s[(i + 2) % 3].rbegin()), r = *(s[(i + 1) % 3].rbegin());
        if (r > l) ans -= sum(C[i], r) - sum(C[i], l);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", ini + 1);
    FOR(i, 1, n) {
        if (ini[i] == 'R') {
            add(C[0], i, 1);
            s[0].insert(i);
        } else if (ini[i] == 'P') {
            add(C[1], i, 1);
            s[1].insert(i);
        } else {
            add(C[2], i, 1);
            s[2].insert(i);
        }
    }
    printf("%d\n", query());
    while (q--) {
        int i;
        scanf("%d%s", &i, op);
        if (ini[i] == 'R') {
            add(C[0], i, -1);
            s[0].erase(i);
        } else if (ini[i] == 'P') {
            add(C[1], i, -1);
            s[1].erase(i);
        } else {
            add(C[2], i, -1);
            s[2].erase(i);
        }
        ini[i] = op[0];
        if (ini[i] == 'R') {
            add(C[0], i, 1);
            s[0].insert(i);
        } else if (ini[i] == 'P') {
            add(C[1], i, 1);
            s[1].insert(i);
        } else {
            add(C[2], i, 1);
            s[2].insert(i);
        }
        printf("%d\n", query());
    }
}