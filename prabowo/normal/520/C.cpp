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

int n;
char s[100002];

LL pangkat (LL x, int y) {
    if (y == 0) return 1;
    return (y & 1) ? x * pangkat (x * x % MOD, y >> 1) % MOD : pangkat (x * x % MOD, y >> 1);
}

int main () {
    scanf("%d", &n);
    gets(s); gets(s);

    int cnt[4]={};
    FOR (i, 0, n) {
        if (s[i] == 'A') cnt[0]++;
        else if (s[i] == 'C') cnt[1]++;
        else if (s[i] == 'G') cnt[2]++;
        else cnt[3]++;
    }

    int ans;

    sort (cnt, cnt+4, greater<int>());
    if (cnt[0] == cnt[1])
        if (cnt[1] == cnt[2])
            if (cnt[2] == cnt[3]) ans = pangkat(4, n);
            else ans = pangkat(3, n);
        else ans = pangkat(2, n);
    else ans = pangkat(1, n);

    printf("%d\n", ans);

    return 0;
}