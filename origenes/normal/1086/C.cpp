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

const int maxn = 1123456;

int t, k, n;
char s[maxn], a[maxn], b[maxn], ans[256];
bool vis[256], flag;

void print() {
    puts("YES");
    int now = 1;
    FOR(i, 1, k) if (!vis[i]) {
            while (ans[now]) now++;
            ans[now] = i;
        }
    FOR(i, 1, k) printf("%c", ans[i] - 1 + 'a');
    puts("");
}

void dfs(int pos, bool fa, bool fb) {
    if (flag) return;
    if (pos == n + 1) {
        flag = true;
        print();
        return;
    }
    if (ans[s[pos]]) {
        if (fa && ans[s[pos]] < a[pos]) return;
        if (fb && ans[s[pos]] > b[pos]) return;
        dfs(pos + 1, fa && ans[s[pos]] == a[pos], fb && ans[s[pos]] == b[pos]);
    } else {
        FOR(i, 1, k) if (!vis[i]) {
                if (fa && i <= a[pos]) continue;
                if (fb && i >= b[pos]) continue;
                vis[i] = true;
                ans[s[pos]] = i;
                flag = true;
                print();
                return;
            }
        if (fa && !vis[a[pos]] && (!fb || a[pos] <= b[pos])) {
            vis[a[pos]] = true;
            ans[s[pos]] = a[pos];
            dfs(pos + 1, fa, fb && a[pos] == b[pos]);
            vis[a[pos]] = false;
            ans[s[pos]] = 0;
        }
        if (fb && !vis[b[pos]] && (!fa || a[pos] <= b[pos])) {
            vis[b[pos]] = true;
            ans[s[pos]] = b[pos];
            dfs(pos + 1, fa && a[pos] == b[pos], fb);
            vis[b[pos]] = false;
            ans[s[pos]] = 0;
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        scanf("%s%s%s", s + 1, a + 1, b + 1);
        n = strlen(s + 1);

        reset(vis, 0);
        reset(ans, 0);
        FOR(i, 1, n) {
            s[i] -= 'a' - 1;
            a[i] -= 'a' - 1;
            b[i] -= 'a' - 1;
        }
        flag = false;
        dfs(1, true, true);
        if (!flag) puts("NO");
    }
}