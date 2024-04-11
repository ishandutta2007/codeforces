#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n;
int a[N];
int pre[N], suf[N];
int lv[N];

struct ITMin {
    int t[N << 2];
    void init(int node, int l, int r) {
        if (l == r) t[node] = l;
        else {
            int m = l + r >> 1;
            init(node << 1, l, m);
            init(node << 1 | 1, m + 1, r);
            if (a[t[node << 1]] < a[t[node << 1 | 1]]) t[node] = t[node << 1];
            else t[node] = t[node << 1 | 1];
        }
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) {
            return t[node];
        }
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        if (a[p1] < a[p2]) return p1;
        return p2;
    }
} itMin;

struct IT {
    int t[N << 2];
    int add[N << 2];

    void addt(int node, int l, int r, int id, int val) {
        if (id > r || id < l) return;
        if (l == r) {
            t[node] = val;
            return;
        }
        int m = l + r >> 1;
        addt(node << 1, l, m, id, val);
        addt(node << 1 | 1, m + 1, r, id, val);
        t[node] = max(t[node << 1], t[node << 1 | 1]) + add[node];
    }

    void change(int node, int l, int r, int x, int y, int delta) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            add[node] += delta;
            t[node] += delta;
            return;
        }
        int m = l + r >> 1;
        change(node << 1, l, m, x, y, delta);
        change(node << 1 | 1, m + 1, r, x, y, delta);
        t[node] = max(t[node << 1], t[node << 1 | 1]) + add[node];
    }


    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) return t[node];
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return max(p1, p2) + add[node];
    }
} it;

int go(int l, int r, int now = 0) {
    if (l > r) return 0;
    int id = itMin.get(1, 1, n, l, r);
    lv[id] = now + 1;   
    go(l, id - 1, now + 1);
    go(id + 1, r, now + 1);
    it.addt(1, 1, n * 2, id, lv[id]);
    return lv[id];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int shift = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) shift = i;
    }
    a[0] = n + 1;
    rotate(a + 1, a + (shift % n) + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i + n] = a[i];
    }
    vector<int> ls;
    for (int i = 1; i <= n * 2; i++) {
        while (!ls.empty() && a[ls.back()] > a[i]) {
            suf[ls.back()] = i;
            ls.pop_back();
        }
        ls.push_back(i);
    }
    ls.clear();
    for (int i = n * 2; i > 0 ; i--) {
        while (!ls.empty() && a[ls.back()] > a[i]) {
            pre[ls.back()] = i;
            ls.pop_back();
        }
        ls.push_back(i);
    }
    itMin.init(1, 1, n);
    go(1, n);
    int res = it.get(1, 1, n * 2, 1, n);
    int num = 0;
    for (int i = 1; i < n; i++) {
        int id = suf[i];
        it.change(1, 1, n * 2, i + 1, id - 1, -1);
        id = pre[i + n];
        lv[i + n] = it.get(1, 1, n * 2, id, id) + 1;
        it.addt(1, 1, n * 2, i + n, lv[i + n]);
        it.change(1, 1, n * 2, id + 1, i + n - 1, 1);
        int now = it.get(1, 1, n * 2, i + 1, i + n);
        if (now < res) {
            res = now;
            num = i;
        }
    }   
    cout << res << ' ' << (num + shift) % n << endl;
    return 0;   
}