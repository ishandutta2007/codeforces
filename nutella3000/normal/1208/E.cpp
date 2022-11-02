#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")
#define int long long
using namespace std;
const int inf = 1e9 + 7;

struct segment_tree {
    vector<int> sum, push;
    int last;

    segment_tree(int n) {
        sum.resize(4 * n, 0);
        push.resize(4 * n, 0);
        last = n - 1;
    }

    void pus(int v) {
        int l = v * 2 + 1;
        int r = v * 2 + 2;
        sum[l] += push[v];
        sum[r] += push[v];
        push[l] += push[v];
        push[r] += push[v];
        push[v] = 0;
    }

    void update(int v) {
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    }

    void add(int l, int r, int x) {
        add(0, 0, last, l, r, x);
    }

    void add(int v, int l, int r, int left, int right, int x) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            push[v] += x;
            sum[v] += x;
            return;
        }
        pus(v);
        int m = ((l + r) >> 1);
        add(v * 2 + 1, l, m, left, right, x);
        add(v * 2 + 2, m + 1, r, left, right, x);
        update(v);
    }

    int get(int id) {
        return get(0, 0, last, id);
    }

    int get(int v, int l, int r, int id) {
        if (l > id || r < id) return 0;
        if (l == id && r == id) return sum[v];
        pus(v);
        int m = ((l + r) >> 1);
        return get(v * 2 + 1, l, m, id) + get(v * 2 + 2, m + 1, r, id);
    }

};

struct fuck {
    vector<int> a;

    fuck(int n) {
        a.resize(n + 1, 0);
    }

    void add(int l, int r, int x) {
        a[l] += x;
        a[r + 1] -= x;
    }

    vector<int> get() {
        for(int i = 1;i < a.size();i++) a[i] += a[i - 1];
        return a;
    }
};



signed main() {
    //freopen("search4.in", "r", stdin);
    //freopen("search4.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int q, w;
    cin >> q >> w;
    w += 2;
    fuck a = fuck(w);
    for(int it = 0;it < q;it++) {
        int n;
        cin >> n;
        n += 2;
        int b[n];
        for(int i = 1;i < n - 1;i++) cin >> b[i];
        b[0] = b[n - 1] = 0;

        deque<int> id;
        for(int i = 0;i < n;i++) {
            while(!id.empty() && b[id.back()] < b[i]) id.pop_back();
            id.emplace_back(i);
            while(!id.empty() && i - id.front() + n - 1 >= w) id.pop_front();

            a.add(i, i, b[id.front()]);
        }

        id.clear();

        for(int i = n - 1;i >= 0;i--) {
            if (w - (n - i) == n - 1) break;
            while(!id.empty() && b[id.back()] < b[i]) id.pop_back();
            id.emplace_back(i);
            while(!id.empty() && w - n + i - id.front() < 0) id.pop_front();

            a.add(w - (n - i), w - (n - i), b[id.front()]);
        }

        int max = 0;
        if (!id.empty()) max = b[id.front()];

        if (w >= 2 * n) a.add(n, w - n - 1, max);
    }

    vector<int> b = a.get();
    for(int i = 1;i < w - 1;i++) cout << b[i] << " ";
}