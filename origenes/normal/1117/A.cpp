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

int n, a, mmax = -1, ans;

int main() {
    scanf("%d", &n);
    int pre = -1, cnt;
    FOR(i, 1, n) {
        scanf("%d", &a);
        if (a > mmax) mmax = a, ans = cnt = 1;
        else if (a == mmax) {
            if (a == pre) cnt++;
            else cnt = 1;
        } else ans = max(ans, cnt), cnt = 0;
        pre = a;
    }
    if (a == mmax) ans = max(ans, cnt);
    printf("%d", ans);
}