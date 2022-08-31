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

    struct state {
        int x, y, dx, dy;
        state(int x, int y, int dx, int dy) : x(x), y(y), dx(dx), dy(dy) { }
        bool operator==(const state &other) const {
            return x == other.x && y == other.y && dx == other.dx && dy == other.dy;
        }
    };

    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd; mint p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        p /= 100;

        auto inside_range = [](int l, int r, int x) -> bool {
            return l <= x && x <= r;
        };

        auto correct_direction = [&](state &s) -> void {
            if (!inside_range(1, n, s.x + s.dx)) {
                s.dx = -s.dx;
            }
            if (!inside_range(1, m, s.y + s.dy)) {
                s.dy = -s.dy;
            }
        };

        auto good_state = [&](const state &s) -> bool {
            return s.x == rd || s.y == cd;
        };

        vector<state> states;
        states.emplace_back(rb, cb, 1, 1);
        correct_direction(states.back());

        state current = states.back();

        while (true) {
            current.x += current.dx;
            current.y += current.dy;
            correct_direction(current);
            if (current == states.front()) {
                break;
            }
            states.push_back(current);
        }

        int total_good_states = 0;
        for (state s : states) {
            total_good_states += good_state(s);
        }

        mint ans = 0, q = (1 - p).pow(total_good_states), mul = 1;

        int good_states = 0;
        for (int i = 0; i < (int) states.size(); i++) {
            if (good_state(states[i])) {
                ans += mul * (i / (1 - q) + states.size() * q / ((1 - q) * (1 - q)));
                mul *= 1 - p;
            }
        }

        ans *= p;
        cout << ans << '\n';
    }
    return 0;
}