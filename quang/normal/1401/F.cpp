#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, q;
int a[1 << N];
bool flip[N], swapVal[N];

struct IT {
    long long sum[4 << N];

    IT() {
        memset(sum, 0, sizeof sum);
    }

    void init(int node, int l, int r) {
        if (l == r) {
            sum[node] = a[l];
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
    }

    void update(int node, int x, int k, int lv) {
        if (lv == 0) {
            sum[node] = k;
            return;
        }
        if (flip[lv]) {
            x = (1 << lv) - x - 1; 
        }
        if (swapVal[lv]) {
            x ^= (1 << lv - 1);
        }
        if (x >> lv - 1 & 1) {
            update(node << 1 | 1, x ^ (1 << lv - 1), k, lv - 1);
        } else {
            update(node << 1, x, k, lv - 1);
        }

        sum[node] = sum[node << 1] + sum[node << 1 | 1];
    }

    long long get(int node, int x, int y, int lv) {
        if (x == 0 && y == (1 << lv) - 1) {
            return sum[node];
        }
        if (flip[lv]) {
            x = (1 << lv) - x - 1;
            y = (1 << lv) - y - 1;
            swap(x, y);
        }
        int m = (1 << lv - 1);
        long long res = 0;
        if (y < m) {
            res += get(node << 1 | swapVal[lv], x, y, lv - 1);
        } else if (x >= m) {
            res += get(node << 1 | (swapVal[lv] ^ 1), x ^ m, y ^ m, lv - 1);
        } else {
            if (!swapVal[lv]) {
                res += get(node << 1, x, m - 1, lv - 1);
                res += get(node << 1 | 1, 0, y ^ m, lv - 1);
            } else {
                res += get(node << 1, 0, y ^ m, lv - 1);
                res += get(node << 1 | 1, x, m - 1, lv - 1);
            }
        }
        return res;
    }
} it;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    it.init(1, 0, (1 << n) - 1);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, k;
            cin >> x >> k;
            x--;
            it.update(1, x, k, n);
        } else if (op == 2) {
            int k;
            cin >> k;
            flip[k] ^= 1;
        } else if (op == 3) {
            int k;
            cin >> k;
            swapVal[k + 1] ^= 1;
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << it.get(1, l, r, n) << '\n';
        }
    }
    return 0;
}