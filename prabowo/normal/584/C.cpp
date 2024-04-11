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
#define INFFW 1000000000
#define INFLL 9000000000000000000LL
#define INFLLFW 4500000000000000000LL
#define EPS 1e-7
#define debug puts("ganteng")
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
#define REV(i, a, b) for (int i=a-1; i>=b; i--)
#define REVV(i, n) REV(i, n, 0)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x) - x.begin())
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

int n, t;
char s[100002];
char ss[100002];
char ans[100002];

int main () {
    scanf("%d %d", &n, &t);
    gets(s);
    gets(s);
    gets(ss);

    int beda = 0;
    FORR(i, n) beda += (s[i] != ss[i]);
    int sama = n - beda;

    if (t < (beda + 1 >> 1)) return 0 * printf("-1\n");

    FORR(i, n) ans[i] = '#';
    ans[n] = '\0';

    int now = 0;
    FORR (i, n) {
        if (s[i] == ss[i]) {
            sama--;
            continue;
        }

        if (t >= n - sama - i) {
            char now = (s[i] - 'a' + 1) % 26;
            if (now == ss[i] - 'a') now = (now + 1) % 26;

            ans[i] = now + 'a';
            t--;
        } else {
            ans[i] = s[i];
            i++;
            while (s[i] == ss[i]) {
                sama--;
                i++;
            }
            ans[i] = ss[i];

            t--;
        }
    }

    FORR (i, n) {
        if (s[i] ^ ss[i]) continue;
        if (t == 0) {
            ans[i] = s[i];
            continue;
        }

        ans[i] = (s[i] - 'a' + 1 ) % 26 + 'a';
        t--;
    }

    puts(ans);

    return 0;
}