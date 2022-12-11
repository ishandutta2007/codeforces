#include <iostream>
#include <map>

using namespace std;

class node {
    public:
        int l, r;
        long long max, lazy;
        node *left, *right;

        node(int _l, int _r, long long _max) :
            l(_l), r(_r), max(_max), lazy(0),
            left(nullptr), right(nullptr) {}
};

const int inf = -1u / 4;
const int N = 1e6 + 10;

map<int, pair<int, int>> join;
long long fen[N];
int q;

node* init(int a, int b) {
    node *p = new node(a, b, b);
    if (a < b) {
        const int mid = (a + b) / 2;
        p->left = init(a, mid);
        p->right = init(mid+1, b);
    } else {
        p->lazy = a;
    }
    return p;
}

long long query(node *p, int t) {
    if (p->r <= t) return p->max;
    if (t < p->l) return -inf;
    return max(query(p->left, t), query(p->right, t)) + p->lazy;
}

void update(node *p, int t, long long v) {
    if (p->l > t) return;
    if (p->r <= t) {
        p->max += v;
        p->lazy += v;
        return;
    }

    update(p->left, t, v);
    update(p->right, t, v);

    p->max = max(p->left->max, p->right->max) + p->lazy;
}

long long query_fen(int idx) {
    long long ans = 0;
    while (idx > 0) {
        ans += fen[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

void update_fen(int idx, long long val) {
    while (idx < N) {
        fen[idx] += val;
        idx += idx & (-idx);
    }
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    node *p = init(1, N);
    cin >> q;

    for (int i = 1; i <= q; ++i) {
        char ch;
        cin >> ch;

        if (ch == '?') {
            int t;
            cin >> t;
            long long ans = query(p, t) - t - query_fen(t);
            cout << ans << '\n';
        } else if (ch == '+') {
            int t, d;
            cin >> t >> d;
            join[i] = {t, d};
            update(p, t, d);
            update_fen(1, d);
            update_fen(t, -d);
        } else if (ch == '-') {
            int idx;
            cin >> idx;

            int a = join[idx].first, b = join[idx].second;
            update(p, a, -b);
            update_fen(1, -b);
            update_fen(a, b);
        }
    }

    return 0;
}