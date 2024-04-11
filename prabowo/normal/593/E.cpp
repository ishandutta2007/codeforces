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
#define sqr(x) (LL)x * (LL)x
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

int n, m, q;
int N;

struct Mat {
    LL a[22][22];

    Mat () {
        FORR(i, N) FORR(j, N) a[i][j] = 0;
    }

    Mat operator * (Mat other) {
        Mat ret;
        FORR(i, N) FORR(j, N) FORR(k, N) ret.a[i][j] += a[i][k] * other.a[k][j], ret.a[i][j] %= MOD;
        return ret;
    }

};

Mat dnc (Mat now, int x) {
    if (x == 0) {
        Mat ret;
        FORR(i, N) ret.a[i][i] = 1;
        return ret;
    }
    return x & 1 ? now * dnc(now * now, x >> 1) : dnc(now * now, x >> 1);
}

int konv (int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return N;
    return x * m + y;
}

int main () {
    scanf("%d %d %d", &n, &m, &q);
    N = n * m;
    int bef = 1;

    Mat kali;
    vi now;

    FORR(i, N) now.pb(0);
    now[0] = 1;

    FORR (i, n) FORR (j, m) {
        kali.a[konv(i, j)][konv(i, j)] = 1;
        kali.a[konv(i, j)][konv(i-1, j)] = 1;
        kali.a[konv(i, j)][konv(i+1, j)] = 1;
        kali.a[konv(i, j)][konv(i, j-1)] = 1;
        kali.a[konv(i, j)][konv(i, j+1)] = 1;
    }

    //FORR(i, N) {FORR(j, N) printf("%d ", kali.a[i][j]); printf("\n");}

    int tp, x, y, t;
    while (q--) {
        scanf("%d %d %d %d", &tp, &x, &y, &t);
        x--, y--;

        Mat tmp = dnc(kali, t - bef);
        bef = t;

        vi next;
        FORR(i, N) {
            LL sum = 0;
            FORR(j, N) sum += tmp.a[i][j] * now[j], sum %= MOD;
            next.pb(sum);
        }

        now = next;
        //FORR(i, n) {FORR(j, m) printf("%d ", now[konv(i, j)]); printf("\n");}

        if (tp == 1) {
            printf("%d\n", now[konv(x, y)]);
        } else if (tp == 2) {
            now[konv(x, y)] = 0;

            kali.a[konv(x, y)][konv(x, y)] = 0;
            kali.a[konv(x, y)][konv(x-1, y)] = 0;
            kali.a[konv(x, y)][konv(x+1, y)] = 0;
            kali.a[konv(x, y)][konv(x, y-1)] = 0;
            kali.a[konv(x, y)][konv(x, y+1)] = 0;

        } else if (tp == 3) {

            kali.a[konv(x, y)][konv(x, y)] = 1;
            kali.a[konv(x, y)][konv(x-1, y)] = 1;
            kali.a[konv(x, y)][konv(x+1, y)] = 1;
            kali.a[konv(x, y)][konv(x, y-1)] = 1;
            kali.a[konv(x, y)][konv(x, y+1)] = 1;
        }
    }
    return 0;
}