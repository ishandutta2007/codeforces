#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 112345;

int n;
char s[maxn];
pii st, en, dir[maxn];

int main() {
    scanf("%d%d", &st._1, &st._2);
    scanf("%d%d", &en._1, &en._2);
    scanf("%d", &n);
    scanf("%s", s + 1);
    FOR(i, 1, n) {
        dir[i] = dir[i - 1];
        if (s[i] == 'U') dir[i]._2++;
        else if (s[i] == 'D') dir[i]._2--;
        else if (s[i] == 'L') dir[i]._1--;
        else dir[i]._1++;
    }
    ll L = 0, R = 1e17;
    while (L < R) {
        ll M = L + R >> 1;
        auto now = mp(st._1 + M / n * dir[n]._1 + dir[M % n]._1, st._2 + M / n * dir[n]._2 + dir[M % n]._2);
        if (abs(now._1 - en._1) + abs(now._2 - en._2) <= M) R = M;
        else L = M + 1;
    }
    if (L > 1e16) L = -1;
    printf("%lld", L);
}