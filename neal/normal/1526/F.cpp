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

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);


const int INF = int(1e9) + 5;

int query(int a, int b, int c) {
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    int result;
    cin >> result;

    if (result == -1)
        exit(0);

    return result;
}

void answer(const vector<int> p) {
    cout << '!';

    for (int x : p)
        cout << ' ' << x;

    cout << endl;
    int result;
    cin >> result;

    if (result == -1)
        exit(0);
}

void run_case() {
    int N;
    cin >> N;

    auto output_from_relative = [&](const vector<int> &relative) -> void {
        vector<int> rank(2 * N + 1, -1);

        for (int i = 0; i < N; i++)
            rank[N + relative[i]] = i;

        int current = 1;
        vector<int> solution(N, -1);

        for (int r : rank)
            if (r >= 0)
                solution[r] = current++;

        answer(solution);
    };

    vector<int> result(N, 0);
    vector<int> occur(N, 0);
    vector<vector<int>> result_list(N);

    for (int i = 2; i < N; i++) {
        result[i] = query(0, 1, i);
        occur[result[i]]++;
        result_list[result[i]].push_back(i);
    }

    int minimum = *min_element(result.begin() + 2, result.end());
    int D;

    if (minimum == 1 && (occur[1] == 2 || occur[2] == 1)) {
        D = 1;
        vector<int> relative(N, -INF);
        relative[0] = 0;
        relative[1] = D;

        vector<int> ones = result_list[1];
        vector<int> twos = result_list[2];
        array<int, 3> consecutive = {-1, -1, -1};

        for (int a : {0, 1})
            for (int b : ones)
                for (int c : twos)
                    if (query(a, b, c) == 1) {
                        consecutive = {a, b, c};
                        break;
                    }

        for (int i = 0; i < N; i++)
            if (result[i] > 0) {
                bool with_a = i == consecutive[1] || query(consecutive[0], consecutive[1], i) < result[i];

                if ((consecutive[0] == 0) ^ with_a)
                    relative[i] = D + result[i];
                else
                    relative[i] = -result[i];
            }

        output_from_relative(relative);
        return;
    }

    D = occur[minimum] == 1 ? 2 * minimum : 2 * minimum - 1;
    vector<int> relative(N, -INF);
    relative[0] = 0;
    relative[1] = D;
    int center = int(min_element(result.begin() + 2, result.end()) - result.begin());

    if (occur[minimum] == 1) {
        relative[center] = D / 2;

        for (int i = 2; i < N; i++)
            if (result[i] < D) {
                if (i == center)
                    continue;

                relative[i] = query(0, i, center) < result[center] ? D - result[i] : result[i];
            }
    } else {
        vector<int> adjacent = result_list[D - 1];
        vector<int> near = D < N - 1 ? result_list[D] : result_list[D - 2];
        int a, b, c;

        while (true) {
            a = int(rng() % 2);
            b = adjacent[rng() % adjacent.size()];
            c = near[rng() % near.size()];

            if (query(a, b, c) <= (D == N - 1 ? 1 : D - 2))
                break;
        }

        // a, b are together
        relative[b] = a == 0 ? 1 : D - 1;

        for (int i = 2; i < N; i++)
            if (result[i] < D) {
                if (i == b)
                    continue;

                int diff = query(a, b, i);
                relative[i] = a == 0 ? diff + 1 : D - (diff + 1);
            }
    }

    int one = int(find(relative.begin(), relative.end(), 1) - relative.begin());

    for (int i = 0; i < N; i++)
        if (result[i] == D) {
            int now = query(0, one, i);

            if (now < D) {
                relative[i] = -now;
            } else if (now > D) {
                relative[i] = now + 1;
            } else {
                int other = query(one, 1, i);

                if (other < D)
                    relative[i] = D + 1;
                else
                    relative[i] = -D;
            }
        }

    for (int i = 0; i < N; i++)
        if (result[i] > D) {
            int now = query(0, one, i);

            if (now > result[i])
                relative[i] = now + 1;
            else
                relative[i] = -now;
        }

    output_from_relative(relative);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}