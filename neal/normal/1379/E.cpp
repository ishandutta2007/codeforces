#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

bool is_power_of_two(int n) {
    return (n & (n - 1)) == 0;
}


vector<int> solution;

bool possible(int n, int k) {
    if (n <= 0 || n % 2 == 0 || k < 0)
        return false;

    if (n <= 3)
        return k == 0;

    if (n == 5)
        return k == 1;

    if (n == 7)
        return k == 0 || k == 2;

    if (n == 9)
        return k == 1 || k == 3;

    int bad = is_power_of_two(n + 1) ? 1 : 0;
    return k <= (n - 3) / 2 && k != bad;
}

void build(int n, int k, int index, int parent) {
    solution[index] = parent;
    dbg(n, k, index, parent);
    assert(n > 0 && possible(n, k));

    if (n == 1)
        return;

    if (n <= 11) {
        for (int a = 1; a <= (n - 1) / 2; a += 2) {
            int b = n - 1 - a;
            int now = 2 * a <= b;

            for (int x = 0; x + now <= k; x++)
                if (possible(a, x) && possible(b, k - x - now)) {
                    build(a, x, index + 1, index);
                    build(b, k - x - now, index + a + 1, index);
                    return;
                }
        }
    }

    if (k == 0) {
        assert(is_power_of_two(n + 1));
        build(n / 2, 0, index + 1, index);
        build(n / 2, 0, index + n / 2 + 1, index);
        return;
    }

    // Try powers of two minus one.
    for (int p = 2; p - 1 < n - 1; p *= 2) {
        int option = p - 1;
        int other = n - 1 - option;
        assert(possible(option, 0));
        int now = (2 * option <= other) || (2 * other <= option);
        int need = k - now;

        if (possible(other, need)) {
            build(option, 0, index + 1, index);
            build(other, need, index + option + 1, index);
            return;
        }
    }

    assert(k > 1);
    build(1, 0, index + 1, index);
    build(n - 2, k - 1, index + 2, index);
    return;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    cin >> N >> K;

    if (!possible(N, K)) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    solution.assign(N, -1);
    build(N, K, 0, -1);
    output_vector(solution, true);
}