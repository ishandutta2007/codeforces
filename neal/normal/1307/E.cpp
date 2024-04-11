#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }
    explicit operator long long() const { return val; }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};


int N, M;
vector<int> grass;
vector<vector<int>> locations;
vector<vector<int>> hungers;

int get_left(int f, int h) {
    int size = locations[f].size();

    if (h > size)
        return -1;

    return locations[f][h - 1];
}

int get_right(int f, int h) {
    int size = locations[f].size();

    if (h > size)
        return -1;

    return locations[f][size - h];
}

pair<int, mod_int> combine(pair<int, mod_int> a, pair<int, mod_int> b) {
    if (a.first > b.first)
        return a;
    else if (b.first > a.first)
        return b;
    else
        return {a.first, a.second + b.second};
}

pair<int, mod_int> solve_split(int left) {
    vector<int> count_before(N + 1, 0), count_after(N + 1, 0);

    for (int i = 0; i < N; i++)
        if (i < left)
            count_before[grass[i]]++;
        else if (i > left)
            count_after[grass[i]]++;

    int cows = 0;
    mod_int ways = 1;

    if (left < 0) {
        for (int f = 1; f <= N; f++) {
            int after = count_after[f];
            int how_many_after = upper_bound(hungers[f].begin(), hungers[f].end(), after) - hungers[f].begin();

            if (how_many_after >= 1) {
                cows++;
                ways *= how_many_after;
            }
        }

        return {cows, ways};
    }

    int sweet = grass[left];

    for (int f = 1; f <= N; f++) {
        if (f == sweet) {
            int need = count_before[f] + 1;
            bool found = false;

            for (int h : hungers[f])
                if (h == need)
                    found = true;

            if (!found)
                return {0, 0};

            int after = count_after[f];
            int how_many = upper_bound(hungers[f].begin(), hungers[f].end(), after) - hungers[f].begin();

            if (need <= after)
                how_many--;

            // while (how_many < (int) hungers[f].size() && hungers[f][how_many] <= after)
            //     how_many++;

            if (how_many == 0) {
                cows++;
            } else {
                cows += 2;
                ways *= how_many;
            }
        } else {
            int before = count_before[f];
            int after = count_after[f];

            if (before > after)
                swap(before, after);

            int how_many_before = upper_bound(hungers[f].begin(), hungers[f].end(), before) - hungers[f].begin();
            int how_many_after = upper_bound(hungers[f].begin(), hungers[f].end(), after) - hungers[f].begin();

            if (how_many_before >= 1 && how_many_after >= 2) {
                cows += 2;
                ways *= how_many_before * (how_many_after - 1);
            } else if (how_many_after >= 1) {
                cows++;
                ways *= how_many_before + how_many_after;
            }
        }
    }

    return {cows, ways};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grass.resize(N);

    for (int &g : grass)
        cin >> g;

    locations.assign(N + 1, {});

    for (int i = 0; i < N; i++)
        locations[grass[i]].push_back(i);

    hungers.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        int f, h;
        cin >> f >> h;
        hungers[f].push_back(h);
    }

    for (int s = 1; s <= N; s++)
        sort(hungers[s].begin(), hungers[s].end());

    pair<int, mod_int> answer = {0, 0};

    for (int i = 0; i < N; i++) {
        answer = combine(answer, solve_split(i));
        // cerr << i << ": " << answer.first << ' ' << answer.second << endl;
    }

    answer = combine(answer, solve_split(-1));
    cout << answer.first << ' ' << answer.second << '\n';
}