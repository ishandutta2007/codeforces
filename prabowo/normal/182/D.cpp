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

char s[100002];
char t[100002];
int fail[100002];

LL gcd(int x, int y) {
    return (y == 0) ? x : gcd(y, x % y);
}

int main () {
    gets(s);
    gets(t);

    fail[0] = -1;
    int i = 0;
    int j = -1;
    int n = strlen(s);
    while (i < n) {
        while (j >= 0 && s[i] != s[j]) j = fail[j];
        fail[++i] = ++j;
    }

    int now = n;
    while (n % (n - fail[now])) now = fail[now];
    int satu = n - fail[now];

    i = 0;
    j = -1;
    int m = strlen(t);
    while (i < m) {
        while (j >= 0 && t[i] != t[j]) j = fail[j];
        fail[++i] = ++j;
    }

    now = m;
    while (m % (m - fail[now])) now = fail[now];
    int dua = m - fail[now];

    if (satu != dua) {
        puts("0");
        return 0;
    }

    for (int i=0; i<satu; i++) {
        if (s[i] != t[i]) {
            puts("0");
            return 0;
        }
    }

    int cnt = 0;
    for (int i=satu; i<=min(n, m); i+=satu) {
        cnt += (n % i == 0 && m % i == 0);
    }

    printf("%d\n", cnt);

    return 0;
}