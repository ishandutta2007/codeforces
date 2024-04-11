#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using P = pair<int, int>;

const int N = 500 + 5;

int n, k, a[N][N], b[N][N], dis[N][N];

struct node {
    int d, x, y;
    bool operator<(const node& b)const {
        return d > b.d;
    }
};
int solve() {
    cin >> n >> k;
    int x1, y1, x2, y2;
    mem(a, 0), mem(b, 0);
    rep(i, 1, n) {
        cin >> x1 >> y1 >> x2 >> y2;
        rep(i, 1, 2) {
            y1 == y2 ? a[min(x1, x2)][y1]++ : b[x1][min(y1, y2)]++;
            x1 = k + 1 - x1, y1 = k + 1 - y1;
            x2 = k + 1 - x2, y2 = k + 1 - y2;
        }
    }
    mem(dis, 63), dis[k / 2][k / 2] = 0;
    priority_queue<node> q;
    q.emplace(0, k / 2, k / 2);
    while(q.size()) {
        auto [d, x, y] = q.top(); q.pop();
        if(d > dis[x][y]) continue;
        if(!x || !y || x == k || y == k) return n - d;
        auto exp = [&](int dx, int dy) {
            dx += x, dy += y;
            int w = (x == dx ? a : b)[max(x, dx)][max(y, dy)] + d;
            if(w < dis[dx][dy]) q.emplace(dis[dx][dy] = w, dx, dy);
        };
        exp(0, 1), exp(1, 0), exp(0, -1), exp(-1, 0);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    for(cin >> T; T--; cout << solve() << '\n');
}