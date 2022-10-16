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

struct Node {
    LL a, b, t;
    bool operator < (const Node &rhs) const {
        return a < rhs.a;
    }
};

const int N = 212345;
const LL INF = LL(4e18);

LL mint[N * 4], minb[N * 4];
Node node[N * 4];
LL minm[N];
int n;

void build(int o, int l, int r) {
    mint[o] = minb[o] = INF;
    if (l == r) return;
    int mid = l + (r - l) / 2;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
}

void update(int o, int l, int r, int pos) {
    if (l == r) {
        minb[o] = node[pos].b;
        mint[o] = node[pos].t;
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) update(o * 2, l, mid, pos);
    else update(o * 2 + 1, mid + 1, r, pos);
    mint[o] = min(mint[o * 2], mint[o * 2 + 1]);
    minb[o] = min(minb[o * 2], minb[o * 2 + 1]);
}

void del(int o, int l, int r, LL val) {
    if (l == r) {
        mint[o] = minb[o] = INF;
        return;
    }
    int mid = l + (r - l) / 2;
    if (minb[o * 2] == val) del(o * 2, l, mid, val);
    else del(o * 2 + 1, mid + 1, r, val);
    mint[o] = min(mint[o * 2], mint[o * 2 + 1]);
    minb[o] = min(minb[o * 2], minb[o * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> node[i].a >> node[i].b >> node[i].t;
    sort(node + 1, node + n + 1);
    minm[n] = node[n].a + node[n].t;
    for (int i = n - 1; i >= 1; --i) minm[i] = min(minm[i + 1], node[i].a + node[i].t);

    build(1, 1, n);
    LL t = node[1].a;
    int pos = 1;
    while (pos <= n && node[pos].a == node[1].a) {
        update(1, 1, n, pos++);
    }

    //cout << pos << endl;
    LL ans = 0;
    for (;;) {
        LL cur_b = minb[1], delta_t = mint[1];
        while (cur_b < INF && t + delta_t > cur_b) {
            del(1, 1, n, cur_b);
            cur_b = minb[1], delta_t = mint[1];
        }
        if (cur_b == INF && pos > n) break;

        //cout << t << endl;
        if (pos > n || cur_b <= node[pos].a) {
            LL k = (cur_b - t) / delta_t;
            ans += k;
            t += k * delta_t;
        } else {
            if (t + delta_t <= node[pos].a) {
                LL k = (node[pos].a - t) / delta_t;
                ans += k;
                t += k * delta_t;
            } else {
                if (t + delta_t <= minm[pos]) t = t + delta_t;
                else t = minm[pos];
                ++ans;
            }
            while (pos <= n && node[pos].a <= t) update(1, 1, n, pos++);
        }
    }

    cout << ans << '\n';
    return 0;
}