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

const int maxn = 15;

ll ans[maxn + 5], n;
set<int> rec[maxn + 5];

int main() {
    scanf("%lld", &n);
    rec[0].insert(0);
    REP(i, maxn) {
        for (int cur : rec[i]) {
            rec[i + 1].insert(cur + 1);
            rec[i + 1].insert(cur + 5);
            rec[i + 1].insert(cur + 10);
            rec[i + 1].insert(cur + 50);
        }
        ans[i] = rec[i].size();
    }
    if (n < maxn) printf("%lld\n", ans[n]);
    else printf("%lld\n", ans[13] + (ans[14] - ans[13]) * (n - 13));
    return 0;
}