#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

int n, xt, yt;
char s[maxn];

bool check(int now) {
    int x = 0, y = 0;
    FOR(i, now + 1, n) {
        if (s[i] == 'R') x++;
        else if (s[i] == 'L') x--;
        else if (s[i] == 'U') y++;
        else y--;
    }
    if (abs(x - xt) + abs(y - yt) <= now) return true;
    int pre = 1;
    FOR(i, now + 1, n) {
        if (s[i] == 'R') x--;
        else if (s[i] == 'L') x++;
        else if (s[i] == 'U') y--;
        else y++;
        if (s[pre] == 'R') x++;
        else if (s[pre] == 'L') x--;
        else if (s[pre] == 'U') y++;
        else y--;
        if (abs(x - xt) + abs(y - yt) <= now) return true;
        pre++;
    }
    return false;
}

int main() {
    scanf("%d%s%d%d", &n, s + 1, &xt, &yt);
    if (abs(xt) + abs(yt) > n || (n - abs(xt) - abs(yt)) & 1) {
        puts("-1");
        return 0;
    }
    int L = 0, R = n;
    while (L < R) {
        int M = L + R >> 1;
        if (check(M)) R = M;
        else L = M + 1;
    }
    printf("%d\n", L);
    return 0;
}