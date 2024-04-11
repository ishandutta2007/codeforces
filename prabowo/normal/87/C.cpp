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

int n;
int dp[100002];

int f(int x) {
    // cout << x << endl;
    // if (x <= 2) return 0;
    if (dp[x] != -1) return dp[x];

    bool nim[100]={};
    for (int i=2; i*(i-1) < 2*x; i++) {
        if ((2 * x - i * (i - 1)) % (2 * i) == 0) {
            int tmp = 0, xx = (2 * x - i * (i - 1)) / (2 * i);
            // cout << x << " " << i << " " << xx << endl;
            FORR(j, i) tmp ^= f(xx + j);

            nim[tmp] = 1;
            if (tmp == 0 && x == n) {
                //cout << xx << endl;
                printf("%d\n", i);
                return 1;
            }
        }
    }

    int ret = 0;
    while (nim[ret]) ret++;
    return dp[x] = ret;
}

int main () {
    scanf("%d", &n);
    memset(dp, -1, sizeof dp);

    //FORR(i, n) printf("%d %d\n", i, f(i));

    if (f(n));
    else printf("-1\n");

    return 0;
}