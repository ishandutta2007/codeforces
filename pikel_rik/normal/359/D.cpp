#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 3e5 + 5;

int n, a[N], tree[2 * N];

inline int combine(int x, int y) {
    return __gcd(x, y);
}

void build() {
    for (int i = 0; i < n; i++)
        tree[i + n] = a[i];

    for (int i = n - 1; i > 0; i--)
        tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
}

int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = combine(ans, tree[l++]);
        if (r & 1) ans = combine(ans, tree[--r]);
    }
    return ans;
}

int tree1[2 * N];

inline int combine1(int x, int y) {
    return min(x, y);
}

void build1() {
    for (int i = 0; i < n; i++)
        tree1[i + n] = a[i];

    for (int i = n - 1; i > 0; i--)
        tree1[i] = combine1(tree1[i << 1], tree1[i << 1 | 1]);
}

int query1(int l, int r) {
    int ans = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = combine1(ans, tree1[l++]);
        if (r & 1) ans = combine1(ans, tree1[--r]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    build();
    build1();

    int lo = 1, hi = n, mid;

    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        bool flag = false;

        for (int i = 0; i + mid < n + 1; i++) {
            if (query(i, i + mid) % query1(i, i + mid) == 0) {
                flag = true;
                break;
            }
        }

        if (flag)
            lo = mid;
        else hi = mid - 1;
    }

    vector<int> ans;
    for (int i = 0; i + lo < n + 1; i++) {
        if (query(i, i + lo) % query1(i, i + lo) == 0)
            ans.push_back(i + 1);
    }

    cout << ans.size() << " " << lo - 1 << "\n";
    for (int i : ans) cout << i << " ";

    return 0;
}