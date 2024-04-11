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
int len[102];
char s[1002];
set <int> huruf[102];

int main () {
    scanf("%d", &n);
    gets(s);

    FORR(i, n) {
        gets(s);
        len[i] = strlen(s);
        FORR(j, len[i]) huruf[i].insert(s[j]);
    }

    int maks = 0;
    FORR(i, n) {
        if (huruf[i].size() > 2) continue;
        FORR(j, n) {
            if (huruf[j].size() > 2) continue;

            set <int> c;
            c.insert(*huruf[i].begin());
            c.insert(*huruf[i].rbegin());
            c.insert(*huruf[j].begin());
            c.insert(*huruf[j].rbegin());

            if (c.size() > 2) continue;

            int tmp = 0;

            FORR(k, n) {
                if (huruf[k].size() > 2) continue;
                tmp += (c.count(*huruf[k].begin()) & c.count(*huruf[k].rbegin())) * len[k];
            }

            MAX(maks, tmp);
        }
    }

    printf("%d\n", maks);

    return 0;
}