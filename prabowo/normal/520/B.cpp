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
bool flag[20002];

int main () {
    scanf("%d %d", &n, &m);
    queue <pii> q;
    q.push(mp(n, 0));
    flag[n] = 1;

    while (q.front().fi != m) {
        pii now = q.front();
        q.pop();

        if (2 * now.fi <= 2 * m && !flag[2*now.fi]) {
            flag[2 * now.fi] = 1;
            q.push(mp(2 * now.fi, now.se + 1));
        }

        if (now.fi - 1 > 0 && !flag[now.fi-1]) {
            flag[now.fi - 1] = 1;
            q.push(mp(now.fi - 1, now.se + 1));
        }
    }

    printf("%d\n", q.front().se);
    return 0;
}