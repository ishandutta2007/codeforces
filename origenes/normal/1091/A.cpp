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

int y, b, r, ans;

int main() {
    scanf("%d%d%d", &y, &b, &r);
    if (y + 1 <= b && y + 2 <= r) ans = 3 * y + 3;
    else if (b - 1 <= y && b + 1 <= r) ans = 3 * b;
    else if (r - 2 <= y && r - 1 <= b) ans = 3 * r - 3;
    printf("%d", ans);
}