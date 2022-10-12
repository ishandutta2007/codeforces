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

int n, k;
int skill[100002];
int nambah[100002];

int main () {
    scanf("%d %d", &n, &k);

    int ans = 0;
    FORR(i, n) {
        scanf("%d", &skill[i]);
        ans += skill[i] / 10;
        nambah[i] = 10 - skill[i] % 10;

        if (nambah[i] == 10) nambah[i] = 0;
        skill[i] += nambah[i];
    }

    sort(nambah, nambah+n);
    FORR(i, n) {
        if (k < nambah[i] || nambah[i] == 0) continue;
        ans++, k -= nambah[i];
    }

    FORR(i, n) {
        int kurang = min(k / 10, 10 - skill[i] / 10);
        k -= kurang * 10;
        ans += kurang;
    }

    printf("%d\n", ans);

    return 0;
}