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

const int maxn = 512345;

char s[maxn];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    pii b, c;
    FOR(i, 1, n) {
        if (s[i] == '[' && !b._1) b._1 = i;
        if (s[i] == ':' && b._1 && !c._1) c._1 = i;
    }
    ROF(i, n, 1) {
        if (s[i] == ']' && !b._2) b._2 = i;
        if (s[i] == ':' && b._2 && !c._2) c._2 = i;
    }
    if (!b._1 || !b._2 || !c._1 || !c._2) {
        puts("-1");
        return 0;
    }
    if (b._1 > b._2 || b._1 > c._2) {
        puts("-1");
        return 0;
    }
    if (b._2 < c._1 || c._1 >= c._2) {
        puts("-1");
        return 0;
    }
    int ans = 4;
    FOR(i, c._1, c._2) ans += s[i] == '|';
    printf("%d", ans);
}