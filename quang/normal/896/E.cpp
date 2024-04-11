#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MAGIC = sqrt(N);

int n, m;
int a[N];

struct Bucket {
    int cnt[N], root[N], delta, max_value;
    int low, high;

    int getRoot(int u) {
        return root[u] == u ? u : root[u] = getRoot(root[u]);
    }

    void init(int l, int r) {
        memset(cnt, 0, sizeof cnt);
        for (int i = l; i < r; i++) {
            cnt[a[i]]++;
        }
        low = l, high = r - 1;
        max_value = N - 1;
        for (int i = 0; i < N; i++) root[i] = i;
        delta = 0;
    }

    void update(int val) {
        if (val * 2 <= max_value) {
            for (int i = 1; i <= val; i++) {
                cnt[delta + i + val] += cnt[delta + i];
                root[delta + i] = delta + i + val;
            }
            delta += val;
            max_value -= val;
        } else if (val < max_value) {
            for (int i = val + 1; i <= max_value; i++) {
                cnt[delta + i - val] += cnt[delta + i];
                root[delta + i] = delta + i - val;
            }
            max_value = val;
        }
    }

    void update(int u, int val) {
        int foo = getRoot(a[u]);
        assert(foo - delta <= max_value);
        if (foo - delta > val) {
            assert(cnt[foo] > 0);
            cnt[foo]--;
            cnt[foo - val]++;
            a[u] = foo - val;
        }
    }

    int get(int val) {
        if (val > max_value) return 0;
        return cnt[val + delta];
    }

    int get(int u, int val) {
        int foo = getRoot(a[u]);
        return (foo - delta) == val;
    }
} b[N / MAGIC + 10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int num_buckets = (n - 1) / MAGIC;
    for (int i = 0; i <= num_buckets; i++) {
        b[i].init(i * MAGIC, min((i + 1) * MAGIC, n));
    }
    while (m--) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        l--, r--;
        int l_bucket = l / MAGIC;
        int r_bucket = r / MAGIC;
        if (op == 1) {
            if (l_bucket == r_bucket) {
                for (int i = l; i <= r; i++) b[l_bucket].update(i, x);
            } else {
                for (int i = l; i <= b[l_bucket].high; i++) b[l_bucket].update(i, x);
                for (int i = b[r_bucket].low; i <= r; i++) b[r_bucket].update(i, x);
                for (int i = l_bucket + 1; i < r_bucket; i++) b[i].update(x);
            }
        } else {
            int res = 0;
            if (l_bucket == r_bucket) {
                for (int i = l; i <= r; i++) res += b[l_bucket].get(i, x);
            } else {
                for (int i = l; i <= b[l_bucket].high; i++) res += b[l_bucket].get(i, x);
                for (int i = b[r_bucket].low; i <= r; i++) res += b[r_bucket].get(i, x);
                for (int i = l_bucket + 1; i < r_bucket; i++) res += b[i].get(x);
            }
            cout << res << '\n';
        }
    }
    return 0;
}