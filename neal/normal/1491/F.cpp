#include <algorithm>
#include <array>
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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N;
    cin >> N;

    auto query = [&](const vector<int> &left, const vector<int> &right) -> int {
        cout << "? " << left.size() << ' ' << right.size() << '\n';
        output_vector(left, true);
        output_vector(right, true);
        cout << flush;
        int result;
        cin >> result;
        return result;
    };

    vector<bool> nonzero(N, false);
    int start = -1;

    for (int i = N - 2; i >= 0; i--) {
        vector<int> right(N - 1 - i);
        iota(right.begin(), right.end(), i + 1);

        if (query({i}, right) != 0) {
            nonzero[i] = true;
            start = i;
            break;
        }
    }

    for (int i = 0; i < start; i++)
        nonzero[i] = query({i}, {start}) != 0;

    int low = start + 1, high = N - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        vector<int> left(mid - low + 1);
        iota(left.begin(), left.end(), low);

        if (query({start}, left) != 0)
            high = mid;
        else
            low = mid + 1;
    }

    nonzero[low] = true;
    vector<int> zero;

    for (int i = 0; i < N; i++)
        if (!nonzero[i])
            zero.push_back(i);

    cout << "! " << zero.size();

    for (int x : zero)
        cout << ' ' << x + 1;

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}