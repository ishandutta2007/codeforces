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

int n, k;
int dp[52];

int f(int x) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];

    bool nim[52] = {};
    nim[f(x-1)] = 1;
    if (x % 2 == 0) {
        if (k & 1) nim[f(x >> 1)] = 1;
        else nim[0] = 1;
    }

    int ret = 0;
    while (nim[ret]) ret++;
    return dp[x]= ret;
}

// if k is divisible by 2
//  if (n % 2 == 0 || n == 1) Kevin wins, else Nicky

// if k is not divisible 2
// if (n > 3)

int ff(int x) {
    if (k % 2 == 0) {
        if (x & 1) return (x == 1);
        return 1 + (x == 2);
    } else {
        if (x == 0 || x == 2 || (x - 1) / 2 >= 2 && x % 2 == 1) return 0;

        int trailing = 0;
        int tmp = x;
        while ((tmp & 1) == 0) {
            trailing++;
            tmp >>= 1;
        }

        if (x % 2 == 0 && (tmp == 1 && trailing % 2 == 0 || tmp == 3 && trailing % 2 == 1 || tmp != 1 && tmp != 3 && trailing % 2 == 0) ) return 2;

        return 1;
    }

}


int main () {
    scanf("%d %d", &n, &k);

    int ans = 0;
    int a;
    FORR(i, n) {
        scanf("%d", &a);
        ans ^= ff(a);
    }

    if (ans) puts("Kevin");
    else puts("Nicky");
    return 0;
}