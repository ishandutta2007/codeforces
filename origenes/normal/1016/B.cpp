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

const int maxn = 1234;

int n, m, q, cnt[maxn];
char s[maxn], t[maxn];

int match(const char *s) {
    REP(i, m) if (s[i] != t[i + 1]) return 0;
    return 1;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s%s", s + 1, t + 1);
    ROF(i, n - m + 1, 0) cnt[i] = cnt[i + 1] + match(s + i);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r - l + 1 < m) puts("0");
        else printf("%d\n", cnt[l] - cnt[r - m + 2]);
    }
    return 0;
}