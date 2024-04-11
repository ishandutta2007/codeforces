#include <bits/stdc++.h>

using namespace std;

template<int MOD>
struct Modular {
    int val;

    Modular(long long u = 0) {
        val = ((u % MOD) + MOD) % MOD;
    }

    bool operator==(const Modular &o) const {
        return val == o.val;
    }

    bool operator!() const {
        return *this == 0;
    }

    Modular operator+(const Modular &o) const {
        int res = val + o.val;
        if (res >= MOD) res -= MOD;
        return {res};
    }

    Modular operator-(const Modular &o) const {
        int res = val - o.val;
        if (res < 0) res += MOD;
        return {res};
    }

    Modular operator*(const Modular &o) const {
        return {1ll * val * o.val % MOD};
    }

    Modular& operator+=(const Modular &o) {
        val += o.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    Modular& operator-=(const Modular &o) {
        val -= o.val;
        if (val < 0) val += MOD;
        return *this;
    }

    Modular& operator*=(const Modular &o) {
        val = 1ll * val * o.val % MOD;
        return *this;
    }

    Modular power(int v) const {
        Modular u = *this;
        Modular res = 1;
        while (v) {
            if (v & 1) res *= u;
            u *= u;
            v >>= 1;
        }
        return res;
    }

    Modular inv() const {
        return {this->power(MOD - 2)};
    }
};
template <int MOD>
ostream& operator<<(ostream& os, const Modular<MOD>& m) {
    return os << m.val;
}
constexpr int MOD = 1000000007;
using Mint = Modular<MOD>;

const int N = 1000010;

int n, p;
int a[N];

bool cmp(deque<pair<int, int>> &u, deque<pair<int, int>> &v) {
    if (u.empty()) return 1;
    if (v.empty()) return 0;
    return u.front().first < v.front().first;
}

void add(deque<pair<int, int>> &q, int val) {
    // cout << "add " << val << endl;
    // cout << q.size() << endl;
    if (q.empty() || q.back().first != val) q.push_back({val, 1});
    else q.back().second++;

    if (q.back().second == p) {
        int cur = q.back().first + 1;
        q.pop_back();
        add(q, cur);
    }
}

Mint getSum(deque<pair<int, int>> &q) {
    Mint res = 0;
    for (auto u : q) {
        Mint base = p;
        res += base.power(u.first) * u.second;
    }
    return res;
}

void normalize(deque<pair<int, int>> &u, deque<pair<int, int>> &v) {
    while (!u.empty() && !v.empty()) {
        if (u.front() == v.front()) {
            u.pop_front();
            v.pop_front();
        } else break;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> p;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        deque<pair<int, int>> q[2];

        if (p == 1) {
            cout << (n % 2) << '\n';
            continue;
        }
        
        for (int i = 1; i <= n; i++) {
            if (cmp(q[0], q[1])) { // q[0] smaller
                add(q[0], a[i]);
            } else {
                add(q[1], a[i]);
            }

            normalize(q[0], q[1]);
        }

        Mint sum[2];
        sum[0] = getSum(q[0]);
        sum[1] = getSum(q[1]);
        Mint res;
        if (cmp(q[0], q[1])) res = sum[1] - sum[0];
        else res = sum[0] - sum[1];
        cout << res << '\n';
    }
    return 0;
}