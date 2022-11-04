#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <cmath>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200100;
int pre[N], a[N];

void dfs (int x) {
    if (x == 0) {
        printf ("RUN %d\n", a[1] - a[0] - 2);
        return;
    }
    dfs (pre[x]);
    printf ("JUMP %d\n", a[x] - a[pre[x] + 1] + 2);
    if (a[x + 1] - a[x] - 2) printf ("RUN %d\n", a[x + 1] - a[x] - 2);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
    }
    a[n++] = m + 1;
    a[n++] = -1;
    sort (a, a + n);
    n = unique (a, a + n) - a;
    int now = 0;
//    for (int i = 0; i < n; i++) cout << a[i] <<' '; cout << endl;
    memset (pre, -1, sizeof pre);
    for (int i = 0; i < n - 1; i++) {
//        cout << i << ' ' << a[i + 1] - a[i] - 2 << endl;
        if (a[i + 1] - a[i] - 2 < s) continue;
        if (i > now) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        int pos = a[i + 1] - 1 + d;
        int p = lower_bound (a, a + n, pos) - a - 1;
//        cout << p << endl;
        if (now < p) {
            for (int j = now + 1; j <= p; j++) pre[j] = i;
            now = p;
        }
    }
    if (pre[n - 2] == -1) cout << "IMPOSSIBLE\n";
    else dfs (n - 2);
}