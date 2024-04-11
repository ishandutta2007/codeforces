#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N;
    cin >> N;
    assert(N % 3 == 0);
    map<array<int, 3>, int> save;
    int queries = 0;

    auto query = [&](int a, int b, int c) -> int {
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        array<int, 3> key = {a, b, c};

        if (save.find(key) != save.end())
            return save[key];

        assert(++queries <= N + 6);
        cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        int result;
        cin >> result;
        return save[key] = result;
    };

    vector<int> status(N, -1);
    vector<int> triple(N / 3, -1);
    array<int, 2> opposite = {-1, -1};

    auto find_opposite = [&](int x) -> array<int, 2> {
        int first = triple[x / 3];
        int second = triple[x / 3 + 1];
        assert(min(first, second) >= 0 && first + second == 1);

        int q0 = query(x, x + 3, x + 4);
        int q1 = query(x, x + 3, x + 5);

        if (q0 != q1) {
            status[x] = first;
            status[x + 3] = second;
            return {x, x + 3};
        }

        int q2 = query(x, x + 4, x + 5);

        if (q0 != q2) {
            status[x] = first;
            status[x + 4] = second;
            return {x, x + 4};
        }

        int q3 = query(x, x + 1, x + 3);

        if (q0 != q3) {
            status[x + 1] = first;
            status[x + 4] = second;
            status[x + 5] = second;
            return {x + 1, x + 4};
        }

        status[x + 2] = first;
        status[x + 3] = second;
        status[x] = query(x, x + 2, x + 3);
        status[x + 1] = !status[x];
        return {x + 2, x + 3};
    };

    int T = -1;

    for (int i = 0; i < N; i += 3) {
        triple[i / 3] = query(i, i + 1, i + 2);

        if (triple[i / 3] != triple[0]) {
            opposite = find_opposite(i - 3);
            T = i - 3;
            break;
        }
    }

    for (int i = N - 1; i >= T; i--)
        if (status[i] < 0)
            status[i] = query(opposite[0], opposite[1], i);

    for (int i = T - 3; i >= 0; i -= 3) {
        int q = query(opposite[1], i, i + 1);

        if (q == triple[i / 3]) {
            status[i] = status[i + 1] = triple[i / 3];
            status[i + 2] = query(opposite[0], opposite[1], i + 2);
        } else {
            status[i + 2] = triple[i / 3];
            status[i] = query(opposite[0], opposite[1], i);
            status[i + 1] = !status[i];
        }
    }

    cout << "! " << N - accumulate(status.begin(), status.end(), 0);

    for (int i = 0; i < N; i++)
        if (status[i] == 0)
            cout << ' ' << i + 1;

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}