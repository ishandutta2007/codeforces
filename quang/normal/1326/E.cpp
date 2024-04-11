#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int pos[N], posBomb[N];

struct IT {
    int minVal[N << 2];
    int sum[N << 2];
    void add(int node, int l, int r, int id, int val) {
        if (id > r || id < l) return;
        if (l == r) {
            sum[node] += val;
            minVal[node] = sum[node];
            return;
        }
        int m = l + r >> 1;
        add(node << 1, l, m, id, val);
        add(node << 1 | 1, m + 1, r, id, val);
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
        minVal[node] = min(minVal[node << 1 | 1], minVal[node << 1] + sum[node << 1 | 1]);
    }
    int getMinVal() {
        return minVal[1];
    }
} it;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        pos[u] = i;
    }
    int cur = n;
    for (int i = 1; i <= n; i++) {
        int id;
        cin >> id;
        while (it.getMinVal() >= 0) {
            it.add(1, 1, n, pos[cur], -1);
            cur--;
        }
        cout << cur + 1 << ' ';
        it.add(1, 1, n, id, 1);
    }
    cout << endl;
    return 0;
}