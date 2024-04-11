#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define MOD 1000000007
#define MOD9 1000000009
#define INF 2000000000
#define INF2 1000000000
#define INFLL 9000000000000000000LL
#define INFLL2 4500000000000000000LL
#define EPS 1e-7
#define debug puts("ganteng")
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i=a-1; i>=b; i--)
#define REVV(i, n) REV(i, n, 0)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x)) - x.begin()
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define sqr(x) (((LL)x) * ((LL)x))
#define SYNC ios_base::sync_with_stdio(0), cin.tie(0)
#define TLE using
#define RTE namespace
#define WA std

TLE RTE WA;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;

typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

int n, k, m, s;
pii a[200002][2];
vii phone[2];

bool cek (int x) {
    vl tmp;
    FORR(j, 2) FORR(i, phone[j].size()) {
        tmp.pb((LL) a[x][j].fi * phone[j][i].fi);
    }
    sort(ALL(tmp));
    LL sum = 0;
    FORR(i, k) sum += tmp[i];
    //cout << x << " " << sum << endl;
    return sum <= s;
}

int main () {
    scanf("%d %d %d %d", &n, &m, &k, &s);

    FORR(j, 2) FORR(i, n) {
        scanf("%d", &a[i][j].fi);
        a[i][j].se = i;

        if (a[i][j].fi < a[i-1][j].fi || i == 0) continue;
        a[i][j] = a[i-1][j];
    }

    //FORR(j, 2) FORR(i, n) printf("%d ", a[i][j]);

    int t, c;
    FORR(i, m) {
        scanf("%d %d", &t, &c);
        phone[--t].pb(mp(c, i));
    }

    FORR(i, 2) {
        sort(ALL(phone[i]));
        if (phone[i].size() > k) phone[i].resize(k);
    }

    int l = 0;
    int r = n - 1;
    int ans = -2;
    while (l <= r) {
        int k = l + r >> 1;
        if (cek(k)) {
            ans = k;
            r = k - 1;
        } else l = k + 1;
    }

    printf("%d\n", ans + 1);
    if (ans == -2) return 0;

    vector <pair<LL, pii> > tmp;
    int x = ans;
    FORR(j, 2) FORR(i, phone[j].size()) {
        tmp.pb(mp((LL) a[x][j].fi * phone[j][i].fi, mp(a[x][j].se, phone[j][i].se)));
    }
    sort(ALL(tmp));
    FORR(i, k) {
        printf("%d %d\n", tmp[i].se.se + 1, tmp[i].se.fi + 1);
    }


    return 0;
}