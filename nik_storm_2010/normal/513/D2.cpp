#include <iostream>
#include <vector>

using namespace std;
const int N = 1e6 + 10;
const int INANE = 2e9;

int tree[4 * N], num_left[N], num_edges[N], max_left[N], min_right[N];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = num_edges[l];
        return;
    }
    int m{};
    m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int get(int i, int l, int r, int ql, int qr) {
    if (l == ql && r == qr)
        return tree[i];
    int m{}, res{};
    m = (l + r) / 2;
    if (ql <= m)
        res = max(res, get(i * 2, l, m, ql, min(qr, m)));
    if (m < qr)
        res = max(res, get(i * 2 + 1, m + 1, r, max(ql, m + 1), qr));
    return res;
}

void modify(int i, int l, int r, int num, int value) {
    if (l == r) {
        tree[i] = value;
        return;
    }
    int m{};
    m = (l + r) / 2;
    if (num <= m)
        modify(i * 2, l, m, num, value);
    else
        modify(i * 2 + 1, m + 1, r, num, value);
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

void dfs(int l, int r) {
    if (l > r)
        return;
    if (l == r) {
        cout << l << " ";
        return;
    }
    if (max_left[l] == l) {
        cout << l << " ";
        dfs(l + 1, r);
    }
    else {
        dfs(l + 1, max_left[l]);
        cout << l << " ";
        dfs(max_left[l] + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n{}, c{};
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        min_right[i] = INANE;
        num_left[i] = num_edges[i] = i;
    }
    for (int i = 1; i <= c; i++) {
        int a{}, b{};
        string s;
        cin >> a >> b >> s;
        if (a >= b) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (s == "LEFT")
            num_left[a] = max(num_left[a], b);
        else
            min_right[a] = min(min_right[a], b);
        num_edges[a] = max(num_edges[a], b);
    }
    build(1, 1, n);
    for (int i = n; i >= 1; i--) {
        max_left[i] = (i == num_left[i] ? i : get(1, 1, n, i + 1, num_left[i]));
        int value{};
        value = get(1, 1, n, i, num_edges[i]);
        modify(1, 1, n, i, value);
        if (max_left[i] >= min_right[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    dfs(1, n);
    cout << "\n";
    return 0;
}