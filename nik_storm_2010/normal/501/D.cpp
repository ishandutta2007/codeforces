#include <iostream>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;

int a[N], b[N], tree[4 * N];

void build_tree(int i, int l, int r) {
    if (l == r) {
        tree[i] = 1;
        return;
    }
    int m{};
    m = (l + r) / 2;
    build_tree(i * 2, l, m);
    build_tree(i * 2 + 1, m + 1, r);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

int sum_tree(int i, int l, int r, int num) {
    if (l == r)
        return 0;
    int m{};
    m = (l + r) / 2;
    int res{};
    if (num <= m)
        res = sum_tree(i * 2, l, m, num);
    else
        res = sum_tree(i * 2 + 1, m + 1, r, num) + tree[i * 2];
    return res;
}

int get_tree(int i, int l, int r, int cnt) {
    if (l == r)
        return l;
    int m{};
    m = (l + r) / 2;
    if (cnt < tree[i * 2])
        return get_tree(i * 2, l, m, cnt);
    else
        return get_tree(i * 2 + 1, m + 1, r, cnt - tree[i * 2]);
}

void modify_tree(int i, int l, int r, int num) {
    if (l == r) {
        tree[i] ^= 1;
        return;
    }
    int m{};
    m = (l + r) / 2;
    if (num <= m)
        modify_tree(i * 2, l, m, num);
    else
        modify_tree(i * 2 + 1, m + 1, r, num);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void convert_to_useful_form(int n) {
    memset(tree, 0, sizeof(tree));
    build_tree(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        int x{};
        x = sum_tree(1, 0, n - 1, a[i]);
        modify_tree(1, 0, n - 1, a[i]);
        a[i] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n{};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    convert_to_useful_form(n);
    for (int i = 0; i < n; i++)
        swap(a[i], b[i]);
    convert_to_useful_form(n);
    int cnt{};
    for (int i = n - 1; i >= 0; i--) {
        cnt++;
        a[i] += b[i];
        if (a[i] >= cnt && i != 0)
            a[i - 1]++;
        if (a[i] >= cnt)
            a[i] -= cnt;
    }
    memset(tree, 0, sizeof(tree));
    build_tree(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        int x{};
        x = get_tree(1, 0, n - 1, a[i]);
        modify_tree(1, 0, n - 1, x);
        a[i] = x;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}