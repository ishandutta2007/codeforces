#include <bits/stdc++.h>
using namespace std;
using lint = long long;

pair<int, int> tree[10000000];
void build(int n, int tl, int tr) {
    if (tl == tr) {
        tree[n].first = 0;
        tree[n].second = tl;
        return;
    }
    int mid = (tl + tr) / 2;
    build(n * 2, tl, mid);
    build(n * 2 + 1, mid + 1, tr);
    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}
void update(int n, int tl, int tr, int p) {
    if (tl == tr) {
        tree[n].first++;
        tree[n].second = tl;
        return;
    }
    int mid = (tl + tr) / 2;
    if (p <= mid) {
        update(n * 2, tl, mid, p);
    } else {
        update(n * 2 + 1, mid + 1, tr, p);
    }
    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int q, x;
    cin >> q >> x;
    build(1, 0, x - 1);
    for (int qi = 0; qi < q; qi++) {
        int y;
        cin >> y;
        y %= x;
        update(1, 0, x - 1, y);
        cout << tree[1].first * x + tree[1].second << "\n";
    }
}