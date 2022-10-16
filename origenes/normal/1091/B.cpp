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

const int maxn = 1123;

pii o[maxn], c;
int n;
map<pii, int> cnt;

pii operator + (pii lhs, pii rhs) {
    return mp(lhs._1 + rhs._1, lhs._2 + rhs._2);
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &o[i]._1, &o[i]._2);
    FOR(i, 1, n) {
        scanf("%d%d", &c._1, &c._2);
        FOR(j, 1, n) cnt[o[j] + c]++;
    }
    for (const auto &it : cnt)
        if (it._2 == n) {
            printf("%d %d", it._1._1, it._1._2);
            return 0;
        }
}