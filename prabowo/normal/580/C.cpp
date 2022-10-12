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
#define MOD9 1000000009
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
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
int cat[100002];
vi edge[100002];

int f(int x, int y, int par) {
    if (y > m) return 0;
    if (edge[x].size() == 1 && x > 0) return 1;

    int ret = 0;
    FORR(i, edge[x].size()) {
        if (edge[x][i] == par) continue;

        if (cat[edge[x][i]]) ret += f(edge[x][i], y + 1, x);
        else ret += f(edge[x][i], 0, x);
    }

    return ret;
}

int main () {
    scanf("%d %d", &n, &m);
    FORR(i, n) scanf("%d", &cat[i]);

    int u, v;
    FORR(i, n-1) {
        scanf("%d %d", &u, &v);
        u--, v--;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    printf("%d\n", f(0, cat[0], 0));

    return 0;
}