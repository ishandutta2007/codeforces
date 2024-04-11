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

pii lis[5];
vector<pii> ans;

int main() {
    FOR(i, 1, 3) scanf("%d%d", &lis[i]._1, &lis[i]._2);
    sort(lis + 1, lis + 4);
    FOR(i, lis[1]._1, lis[2]._1 - 1) ans.eb(i, lis[1]._2);
    FOR(i, min(lis[1]._2, lis[2]._2), max(lis[1]._2, lis[2]._2))
        ans.eb(lis[2]._1, i);
    ROF(i, lis[3]._1, lis[2]._1 + 1) ans.eb(i, lis[3]._2);
    if (lis[3]._2 > lis[1]._2 && lis[3]._2 > lis[2]._2)
        FOR(i, max(lis[2]._2, lis[1]._2) + 1, lis[3]._2) ans.eb(lis[2]._1, i);
    if (lis[3]._2 < lis[1]._2 && lis[3]._2 < lis[2]._2)
        FOR(i, lis[3]._2, min(lis[1]._2, lis[2]._2) - 1) ans.eb(lis[2]._1, i);
    printf("%d\n", ans.size());
    for (auto u : ans) printf("%d %d\n", u._1, u._2);
}