#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
const int MAXN = 2e5 + 5;

int n, m;
vector <pll > isl;
vector <pair <ll, int> > br;
vector <pll > edges;
int ans[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        ll l, r;
        scanf("%I64d%I64d", &l, &r);
        isl.puba(mapa(l, r));
    }

    for (int i = 0; i < m; ++i) {
        ll num;
        scanf("%I64d", &num);
        br.puba(mapa(num, i));
    }

    sort(bend(br));

    vector <pair <pair <ll, int>, int> > scanline;

    for (int i = 0; i < n - 1; ++i) {
        edges.puba(mapa(isl[i + 1].ff - isl[i].ss, isl[i + 1].ss - isl[i].ff));
        scanline.puba(mapa(mapa(isl[i + 1].ff - isl[i].ss, 0), i));
        scanline.puba(mapa(mapa(isl[i + 1].ss - isl[i].ff, 2), i));
    }

    for (int i = 0; i < m; ++i) {
        scanline.puba(mapa(mapa(br[i].ff, 1), br[i].ss));
    }

    sort(bend(scanline));
         
    //sort(bend(edges));

    memset(ans, -1, sizeof ans);

    set <pair <ll, int> > now;

    for (int i = 0; i < szof(scanline); ++i) {
        if (scanline[i].ff.ss == 0) {
            now.insert(mapa(edges[scanline[i].ss].ss, scanline[i].ss));
        } else if (scanline[i].ff.ss == 2) {
            if (ans[scanline[i].ss] == -1) {
                printf("No\n");
                return 0;
            }
        } else {
            if (szof(now)) {
                pair <ll, int> p = *now.begin();
                now.erase(p);
                ans[p.ss] = scanline[i].ss;
            }
        }
    }

    printf("Yes\n");

    for (int i = 0; i < n -1; ++i) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");

    return 0;
}