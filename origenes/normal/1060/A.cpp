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

const int maxn = 123;

int n, cnt[2];
char s[maxn];

int main() {
    scanf("%d%s", &n, s);
    REP(i, n) {
        if (s[i] == '8') cnt[0]++;
        else cnt[1]++;
    }
    int ans = 0;
    if (cnt[0] * 10 <= cnt[1]) ans = cnt[0];
    else {
        while (cnt[0]--) {
            cnt[1]++;
            if (cnt[0] * 10 <= cnt[1]) {
                ans = cnt[0];
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}