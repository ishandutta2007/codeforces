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

int n;
int a[500002];
int b[500002];
int c[500002];
int ans1[500002];
int ans2[500002];

int main () {
    scanf("%d", &n);
    FORR(i, n) scanf("%d", &a[i]), b[i] = a[i], c[i] = a[i];

    FOR(i, 1, n-1) {
        if ((a[i] ^ a[i-1]) && (a[i] ^ a[i+1])) {
            ans1[i] = ans1[i - 1] + 1;
        }
    }

    REV(i, n-1, 1) {
        if ((a[i] ^ a[i-1]) && (a[i] ^ a[i+1])) {
            ans2[i] = ans2[i + 1] + 1;
        }
    }

    FOR(i, 1, n-1) if ((b[i] ^ b[i-1]) && (b[i] ^ b[i+1])) b[i] = b[i-1];
    REV(i, n-1, 1) if ((c[i] ^ c[i-1]) && (c[i] ^ c[i+1])) c[i] = c[i+1];

    //FORR(i, n) printf("%d %d\n", b[i], c[i]);

    int maks = 0;
    FORR(i, n) {
        if (ans1[i] < ans2[i]) {
            MAX(maks, ans1[i]);
            a[i] = b[i];
        } else {
            MAX(maks, ans2[i]);
            a[i] = c[i];
        }
    }

    printf("%d\n", maks);
    FORR(i, n) printf("%d ", a[i]);
    printf("\n");

    return 0;
}