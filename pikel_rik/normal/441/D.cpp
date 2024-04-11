#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3000 + 5;

class UnionFind {
public:
    int n;
    vector<int> p, r;

    UnionFind(): n(), p(), r() {}
    UnionFind(int n): n(n), p(n), r(n) {
        iota(p.begin(), p.end(), 0);
    }
    int size() const {
        return n;
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 == l2)
            return false;
        if (r[l1] > r[l2])
            p[l2] = l1;
        else if (r[l1] < r[l2])
            p[l1] = l2;
        else {
            p[l2] = l1;
            r[l1]++;
        }
        n--;
        return true;
    }
};

int n, a[N], m, id[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    iota(id, id + N, 0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;

    int f = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int ptr = a[i], length = 1;

            while (ptr != i) {
                id[ptr] = i;
                visited[ptr] = true;
                ptr = a[ptr];
                length++;
            }
            f += length - 1;
        }
    }

    vector<pair<int, int>> ans;

    if (f < m) {
        UnionFind uf(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (id[i] == id[j]) {
                    uf.merge(i, j);
                }
            }
        }
        for (int i = 1; i <= n and f < m; i++) {
            for (int j = i + 1; j <= n and f < m; j++) {
                if (uf.merge(i, j)) {
                    ans.emplace_back(i, j);
                    f++;
                }
            }
        }
    } else if (f > m) {
        auto traverse = [&] (int x) {
            id[x] = x;
            int ptr = a[x];
            while (ptr != x) {
                id[ptr] = x;
                ptr = a[ptr];
            }
        };

        for (int i = 1; i <= n and f > m; i++) {
            for (int j = i + 1; j <= n and f > m; j++) {
                if (id[i] == id[j]) {
                    swap(a[i], a[j]);
                    traverse(i);
                    traverse(j);
                    ans.emplace_back(i, j);
                    f--;
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto& [i, j] : ans) cout << i << ' ' << j << ' '; cout << '\n';
    return 0;
}