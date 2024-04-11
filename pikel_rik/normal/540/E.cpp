#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

template <typename T>
class FenwickTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    FenwickTree(int n, F f = plus<T>()): n(n), bit(n + 1, 0), f(f) {}

    void add(int i, int val) {
        while (i <= n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        T ans = T();
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};

int n, a[N], b[N];

vector<int> compress() {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back(a[i]);
        temp.push_back(b[i]);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (!mp[a[i]]) {
            mp[a[i]] = a[i];
        }
        if (!mp[b[i]]) {
            mp[b[i]] = b[i];
        }
        swap(mp[a[i]], mp[b[i]]);
    }

    vector<int> temp = compress();
    ll ans = 0;

    FenwickTree<int> ft1(temp.size()), ft2(temp.size());

    for (auto& [i, x] : mp) {
        int idxi = lower_bound(temp.begin(), temp.end(), i) - temp.begin() + 1;
        int idxx = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
        ans += ft1.query(temp.size()) - ft1.query(idxx);
        if (x < i) {
            ans += i - x - 1 - (ft2.query(idxi) - ft2.query(idxx)); //(i - 1) to (x + 1)
        } else if (x > i) {
            ans += x - i - 1 - (idxx - idxi - 1 - (ft2.query(idxx - 1) - ft2.query(idxi))); //(x - 1) to (i + 1)
        }
        ft1.add(idxx, 1);
        ft2.add(idxi, 1);
    }
    cout << ans << '\n';
    return 0;
}