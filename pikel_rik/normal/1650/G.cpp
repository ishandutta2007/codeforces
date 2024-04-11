#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
    static_assert(0 < M, "Module must be positive");

    constexpr static auto get_m() {
        return M;
    }

    int val;

    constexpr auto get_val() {
        return val;
    }

    constexpr static_mint() : val() {}

    constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

    constexpr static_mint pow(long long n) const {
        static_mint ans = 1, x(*this);
        for (; n > 0; n /= 2) {
            if (n & 1) ans *= x;
            x *= x;
        }
        return ans;
    }

    constexpr static_mint inv() const {
        return pow(M - 2);
    }

    constexpr static_mint operator+() const {
        static_mint m;
        m.val = val;
        return m;
    }

    constexpr static_mint operator-() const {
        static_mint m;
        m.val = (val == 0 ? 0 : M - val);
        return m;
    }

    constexpr static_mint &operator+=(const static_mint &m) {
        if ((val += m.val) >= M) val -= M;
        return *this;
    }

    constexpr static_mint &operator-=(const static_mint &m) {
        if ((val -= m.val) < 0) val += M;
        return *this;
    }

    constexpr static_mint &operator*=(const static_mint &m) {
        val = (long long) val * m.val % M;
        return *this;
    }

    constexpr static_mint &operator/=(const static_mint &m) {
        val = (long long) val * m.inv().val % M;
        return *this;
    }

    constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) += rhs;
    }

    constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) -= rhs;
    }

    constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) *= rhs;
    }

    constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) /= rhs;
    }

    constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
        return lhs.val == rhs.val;
    }

    constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
        return lhs.val != rhs.val;
    }

    constexpr static_mint &operator++() {
        return *this += 1;
    }

    constexpr static_mint &operator--() {
        return *this -= 1;
    }

    constexpr static_mint operator++(int) {
        static_mint result(*this);
        *this += 1;
        return result;
    }

    constexpr static_mint operator--(int) {
        static_mint result(*this);
        *this -= 1;
        return result;
    }

    template<typename T>
    constexpr explicit operator T() const {
        return T(val);
    }

    friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
        return os << m.val;
    }

    friend std::istream &operator>>(std::istream &is, static_mint &m) {
        long long x;
        return is >> x, m = x, is;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using mint = static_mint<1000000007>;

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int s, t;
        cin >> s >> t, --s, --t;

        vector<vector<int>> g(n);
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v, --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        auto bfs = [&](int src) -> pair<vector<int>, vector<mint>> {
            vector<int> lvl(n, -1);
            vector<mint> n_paths(n, 0);

            queue<int> q;
            q.push(src);
            lvl[src] = 0, n_paths[src] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (lvl[v] == -1) {
                        q.push(v);
                        lvl[v] = 1 + lvl[u];
                    }
                    if (lvl[v] == 1 + lvl[u]) {
                        n_paths[v] += n_paths[u];
                    }
                }
            }

            return make_pair(lvl, n_paths);
        };

        auto[lvl_s, n_paths_s] = bfs(s);
        auto[lvl_t, n_paths_t] = bfs(t);

        mint ans = n_paths_s[t];

        for (int u = 0; u < n; u++) {
            for (int v : g[u]) {
                if (lvl_s[u] == lvl_s[v] && lvl_s[u] + lvl_t[v] == lvl_s[t]) {
                    ans += n_paths_s[u] * n_paths_t[v];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}