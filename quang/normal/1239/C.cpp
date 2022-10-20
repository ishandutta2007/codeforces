#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long INF = 1e18;

int n, p;
int t[N];
long long res[N];

struct IT {
    long long minVal[N << 2];

    void init(int node, int l, int r) {
        if (l == r) {
            minVal[node] = t[l];
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        minVal[node] = min(minVal[node << 1], minVal[node << 1 | 1]);
    }

    int getFirstPos(int node, int l, int r, long long curTime) {
        if (l == r) return l;
        int m = l + r >> 1;
        if (minVal[node << 1] <= curTime) return getFirstPos(node << 1, l, m, curTime);
        return getFirstPos(node << 1 | 1, m + 1, r, curTime);
    }

    void update(int node, int l, int r, int id) {
        if (id > r || id < l) return;
        if (l == r) {
            minVal[node] = INF;
            return;
        }
        int m = l + r >> 1;
        update(node << 1, l, m, id);
        update(node << 1 | 1, m + 1, r, id);
        minVal[node] = min(minVal[node << 1], minVal[node << 1 | 1]);
    }

    long long getMin(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return INF;
        if (x <= l && r <= y) return minVal[node];
        int m = l + r >> 1;
        long long p1 = getMin(node << 1, l, m, x, y);
        long long p2 = getMin(node << 1 | 1, m + 1, r, x, y);
        return min(p1, p2);
    }
} it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    it.init(1, 1, n);
    deque<int> q;
    long long curTime = 0;
    while (1) { 
        if (q.empty()) {
            long long minVal = it.minVal[1];
            if (minVal == INF) break;
            if (minVal > curTime) curTime = minVal;
            int id = it.getFirstPos(1, 1, n, curTime);
            it.update(1, 1, n, id);
            q.push_back(id);
        }
        // taking water
        while (1) {
            int u = q.back();
            long long minVal = it.getMin(1, 1, n, 1, u - 1);
            if (minVal < curTime + p) {
                int id = it.getFirstPos(1, 1, n, minVal);
                it.update(1, 1, n, id);
                q.push_back(id);
            } else break;
        }
        int u = q.front();
        q.pop_front();
        res[u] = curTime + p;
        curTime += p;
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << endl;
    return 0;
}