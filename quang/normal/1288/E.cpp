#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m;

struct BIT {
    int t[N];
    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += x & -x;
        }
    }
    int get(int x) {
        int res = 1;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} t;

int minTime[N], maxTime[N];
int last[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;   
    for (int i = 1; i <= n; i++) {
        minTime[i] = i;
        maxTime[i] = i;
        last[i] = -1;
    }
    int cur = 0;
    for (int i = n; i; i--) {
        cur++;
        t.add(cur, 1);
        last[i] = cur;
    }
    for (int i = 1; i <= m; i++) {
        cur++;
        int u;
        cin >> u;
        minTime[u] = 1;
        maxTime[u] = max(maxTime[u], t.get(last[u] + 1, cur - 1) + 1);
        t.add(cur, 1);
        t.add(last[u], -1);
        last[u] = cur;
    }
    cur++;
    for (int i = 1; i <= n; i++) {
        maxTime[i] = max(maxTime[i], t.get(last[i] + 1, cur - 1) + 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << minTime[i] << ' ' << maxTime[i] << '\n';
    }
    return 0;
}