#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) FOR(i, 0, (n) - 1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
using LL = long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 112;

int a[N][N];
int cnt[N];
int n, m;
vector<int> ans;
int num;

void solve(int id) {
    vector<int> vec;
    vector<int> ans_cur;
    for (int i = 1; i <= m; ++i) vec.pb(i);
    sort(all(vec), [id](int x, int y) { return a[x][id] - a[x][n] < a[y][id] - a[y][n]; });

    int x = cnt[id], y = cnt[n], tot = 0;
    for (int i = 0; i < m; ++i) {
        int cur = vec[i];
        x -= a[cur][id], y -= a[cur][n];
        ans_cur.pb(cur);
        ++tot;
        if (x >= y) break;
    }

    if (tot < num) {
        num = tot;
        ans = ans_cur;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            cnt[j] += a[i][j];
        }
    }

    for (int i = 1; i < n; ++i) {
        if (cnt[i] >= cnt[n]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    num = n + 1;
    for (int i = 1; i < n; ++i) solve(i);

    cout << num << '\n';
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
    return 0;
}