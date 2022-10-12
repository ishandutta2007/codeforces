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
int a[102];
int b[102];
int c[102];

int arr[102];

int main () {
    scanf("%d", &n);
    FORR(i, n-1) scanf("%d", &a[i]);
    FORR(i, n-1) scanf("%d", &b[i]);

    FORR(i, n) scanf("%d", &c[i]);

    FORR(i, n-1) a[i] += a[i-1];
    REVV(i, n-1) b[i] += b[i+1];

    FORR(i, n) arr[i] = a[i-1] + c[i] + b[i];

    sort(arr, arr+n);

    printf("%d\n", arr[0] + arr[1]);

    return 0;
}