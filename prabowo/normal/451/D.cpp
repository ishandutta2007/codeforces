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
pll odd[2];
LL huruf[2];

LL C(LL x) {
    return (x + 1) * x / 2;
}

int main () {
    gets(s);
    int n = strlen(s);

    for (int i=0; i<n; i++) {
        huruf[s[i]-'a']++;
        if ((huruf[0] + huruf[1]) & 1) odd[s[i]-'a'].fi++;
        else odd[s[i]-'a'].se++;
    }

    LL ganjil = C(odd[0].fi) + C(odd[0].se) + C(odd[1].fi) + C(odd[1].se);
    LL genap = C(huruf[0]) + C(huruf[1]) - ganjil;

    printf ("%I64d %I64d\n", genap, ganjil);

    return 0;
}