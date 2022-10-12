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

int m;
set <pii> ada;
map <pii, int> brp;
set <int> bisa;
map <pii, int> nomor;
pii cube[100002];

int main () {
    scanf("%d", &m);

    pii point;
    FOR (i, 0, m) {
        scanf("%d %d", &point.fi, &point.se);
        cube[i] = point;

        nomor[point] = i;
        ada.insert(point);

        brp[mp(point.fi+0, point.se+1)]++;
        brp[mp(point.fi-1, point.se+1)]++;
        brp[mp(point.fi+1, point.se+1)]++;
    }

    FOR (i, 0, m) {
        bool ok = 1;
        FOR (j, -1, 2) {
            pii tmp = mp(cube[i].fi + j, cube[i].se + 1);
            if (ada.count(tmp) && brp[tmp] == 1) ok = 0;
        }
        if (ok) bisa.insert(i);
    }

    LL ans = 0;
    bool now = 0;
    pii ambil;
    int idx;
    FOR (i, 0, m) {
        //cout << bisa.size() << " : " << *(bisa.begin()) << endl;
        now ^= 1;
        if (now) idx = *(bisa.rbegin());
        else idx = *(bisa.begin());
        //cout << idx << endl;

        bisa.erase(idx);
        ambil = cube[idx];
        ada.erase(ambil);
        ans *= m, ans += idx, ans %= (MOD+2);

        FOR (j, -1, 2) {
            pii tmp = mp(ambil.fi + j, ambil.se + 1);
            if (ada.count(tmp)) {
                int cnt = --brp[tmp];
                if (cnt == 1) {
                    FOR (k, -1, 2) {
                        pii tmp2 = mp(tmp.fi + k, ambil.se);
                        if (ada.count(tmp2)) bisa.erase(nomor[tmp2]);
                    }
                }
            }

            tmp = mp(ambil.fi + j, ambil.se - 1);
            if (ada.count(tmp)) {
                bool ok = 1;
                FOR (k, -1, 2) {
                    pii tmp2 = mp(tmp.fi + k, ambil.se);
                    if (ada.count(tmp2) && brp[tmp2] == 1) ok = 0;
                }
                if (ok) bisa.insert(nomor[tmp]);
            }
        }
    }

    printf("%I64d\n", ans);
    return 0;
}