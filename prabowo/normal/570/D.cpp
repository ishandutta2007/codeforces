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
#define MOD 1000000007
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x) - x.begin())
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SYNC ios_base::sync_with_stdio(0)
#define kita using
#define emang namespace
#define ganteng std

kita emang ganteng;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;
typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

int n, m;
vi child[500002];
char s[500002];
char t[500002];
pii range[500002];
pii palin[500002];
int sum[26][500002];

int idx = 1;

int order (int x) {
    range[x].fi = idx;
    FOR (i, 0, child[x].size()) order (child[x][i]);
    range[x].se = idx++;
    return 0;
}

void bfs () {
    queue <pii> q; // fi depth, se x
    q.push(mp(1, 1));
    int idx = 1;
    while (q.size()) {
        pii now = q.front();
        q.pop();
        t[idx] = s[now.se - 1];
        palin[idx++] = mp(now.fi, range[now.se].se);
        FOR (i, 0, child[now.se].size()) q.push(mp(now.fi + 1, child[now.se][i]));
    }
    return;
}

int main () {
    scanf("%d %d", &n, &m);

    int p;
    FOR (i, 2, n+1) {
        scanf("%d", &p);
        child[p].pb(i);
    }


    if (n == 1) gets(s);
    gets(s);
    gets(s);

    order (1);
    bfs();

    FOR (i, 1, n+1) {
        sum[t[i]-'a'][i] = 1;
        FOR (j, 0, 26) sum[j][i] += sum[j][i-1];
    }

    int v, h;
    while (m--) {
        scanf ("%d %d", &v, &h);
        int atas = upper_bound(palin+1, palin+n+1, mp(h, range[v].se)) - palin;
        int bawah = lower_bound(palin+1, palin+n+1, mp(h, range[v].fi)) - palin;
        int odd = 0;

        FOR (i, 0, 26) odd += ((sum[i][atas-1] - sum[i][bawah-1]) & 1);

        odd > 1 ? puts("No") : puts("Yes");
    }

    return 0;
}