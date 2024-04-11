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
#define UNIK(x) unique(ALL(x)) - x.begin()
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
vii titik;

int main () {
    scanf("%d %d", &n, &m);

    titik.pb(mp(0, 0));
    titik.pb(mp(n, m));
    titik.pb(mp(0, min(1, m)));
    titik.pb(mp(min(1, n), 0));
    titik.pb(mp(n, max(m-1, 0)));
    titik.pb(mp(max(n-1, 0), m));
    titik.pb(mp(0, m));
    titik.pb(mp(n, 0));

    sort(ALL(titik));
    titik.resize(UNIK(titik));

    double jarak = 0;
    vii ans;

    for (int i=0; i<(1<<titik.size()); i++) {
        if (__builtin_popcount(i) == 4) {
            vii coba;
            for (int j=0; j<titik.size(); j++) {
                if ((i >> j) & 1) coba.pb(titik[j]);
            }
            do {
                double tmp = 0;
                for (int j=1; j<coba.size(); j++) tmp += hypot(coba[j].fi - coba[j-1].fi, coba[j].se - coba[j-1].se);
                if (tmp + EPS > jarak) {
                    jarak = tmp;
                    ans = coba;
                }
            } while (next_permutation(ALL(coba)));
        }
    }

    for (int i=0; i<ans.size(); i++) {
        printf("%d %d\n", ans[i].fi, ans[i].se);
    }

    return 0;
}