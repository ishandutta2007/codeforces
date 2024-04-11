#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 312345;

char s[maxn];
int n, x, y, cnt[2], p = -1;

int main() {
    scanf("%d%d%d", &n, &x, &y);
    scanf("%s", s);
    REP(i, n) {
        int now = s[i] - '0';
        if (now == p) continue;
        cnt[now]++;
        p = now;
    }
    if (!cnt[0]) puts("0");
    else {
        ll ans = ll(cnt[0] - 1) * min(x, y) + y;
        printf("%lld\n", ans);
    }
    return 0;
}