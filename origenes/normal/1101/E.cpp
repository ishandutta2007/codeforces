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

int n;
pii mmin, cur;
char op[5];

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%s%d%d", op, &cur._1, &cur._2);
        if (cur._1 > cur._2) swap(cur._1, cur._2);
        if (op[0] == '+') {
            mmin._1 = max(mmin._1, cur._1);
            mmin._2 = max(mmin._2, cur._2);
        } else puts(mmin._1 <= cur._1 && mmin._2 <= cur._2 ? "YES" : "NO");
    }
}