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

const int maxn = 512;

int n, deg[maxn], tot, cnt;
vector<int> v;
queue<int> q;

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", deg + i);
        tot += deg[i];
        if (deg[i] == 1) cnt++;
    }
    if (tot < 2 * n - 2) {
        puts("NO");
        return 0;
    }
    printf("YES ");
    if (cnt <= 2) printf("%d\n", n - 1);
    else printf("%d\n", n - cnt + 1);
    printf("%d\n", n - 1);
    FOR(i, 1, n) {
        if (deg[i] >= 2) v.pb(i);
        else q.push(i);
    }
    FOR(i, 1, int(v.size()) - 1) {
        deg[v[i - 1]]--;
        deg[v[i]]--;
        printf("%d %d\n", v[i - 1], v[i]);
    }
    int now = 0;
    if (!q.empty()) {
        int u = q.front(); q.pop();
        deg[v[0]]--;
        printf("%d %d\n", u, v[0]);
    }
    if (!q.empty()) {
        int u = q.front(); q.pop();
        deg[v.back()]--;
        printf("%d %d\n", u, v.back());
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        while (!deg[v[now]]) now++;
        deg[v[now]]--;
        printf("%d %d\n", u, v[now]);
    }
}