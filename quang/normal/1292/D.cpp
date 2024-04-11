#include <bits/stdc++.h>

using namespace std;

const int M = 5001;

int p[M];
vector<int> val[M];
int id[M];
int w[M];
long long sumW[M], sumLenW[M];
long long res;

vector<int> divs(int u) {
    vector<int> res;
    while (u > 1) {
        int v = p[u];
        while (u % v == 0) {
            u /= v;
            res.push_back(v);
        }
    }
    return res;
}

void add(vector<int> &u, int v) {
    int id = u.size();
    u.push_back(v);
    while (id >= 1 && u[id] > u[id - 1]) {
        swap(u[id], u[id - 1]);
        id--;
    }
}

long long getSum(long long *a, int l, int r) {
    if (l > r) return 0ll;
    return a[r] - (l > 0 ? a[l - 1] : 0ll);
}

void solve(int lv, int l, int r, long long cost, long long wOut) {
    long long now = getSum(sumLenW, l, r) - 1ll * lv * getSum(sumW, l, r);
    res = min(res, now + cost);
    int s = l;
    while (val[id[s]].size() == lv) s++;
    for (int x = s, y = s; x <= r; x = y) {
        while (y <= r && val[id[x]][lv] == val[id[y]][lv]) y++;
        y--;

        long long cost2 = cost;
        long long wOut2 = wOut;
        cost2 += getSum(sumLenW, l, x - 1) - 1ll * lv * getSum(sumW, l, x - 1);
        cost2 += getSum(sumLenW, y + 1, r) - 1ll * lv * getSum(sumW, y + 1, r);
        wOut2 += getSum(sumW, l, x - 1) + getSum(sumW, y + 1, r);
        cost2 += wOut2;
        solve(lv + 1, x, y, cost2, wOut2);

        y++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < M; i++) {
        if (!p[i]) {
            for (int j = i; j < M; j += i) {
                if (!p[j]) p[j] = i;
            }
        }
    }
    vector<int> cur;
    for (int i = 2; i < M; i++) {
        vector<int> now = divs(i);
        for (int u : now) add(cur, u);
        val[i] = cur;
    }   
    for (int i = 0; i < M; i++) {
        id[i] = i;
    }
    sort(id, id + M, [&](int u, int v) {
        return val[u] < val[v];
    });
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        w[u]++;
    }
    for (int i = 0; i < M; i++) {
        int u = id[i];
        sumW[i] = w[u];
        sumLenW[i] = 1ll * w[u] * val[u].size();
        if (i > 0) {
            sumW[i] += sumW[i - 1];
            sumLenW[i] += sumLenW[i - 1];
        }
    }
    res = 1e18;
    solve(0, 0, M - 1, 0ll, 0ll);
    cout << res << endl;
    return 0;
}