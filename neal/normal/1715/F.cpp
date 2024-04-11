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

// Uniformly distributed real number in [a, b).
double real_rng(double a = 0, double b = 1) {
    assert(a <= b);
    return uniform_real_distribution<double>(a, b)(rng);
}


int main() {
    ios::sync_with_stdio(false);

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    auto build_polygon = [&](int N, int M, vector<double> lengths, bool flip) -> vector<array<double, 2>> {
        vector<array<double, 2>> polygon = {{0, -1}};
        double x = 0;

        for (int i = 0; i < int(lengths.size()); i++) {
            double y = i % 2 == 0 ? M : 0;
            polygon.push_back({x, y});
            x += lengths[i];
            polygon.push_back({x, y});
        }

        polygon.push_back({double(N), -1});

        if (flip) {
            for (auto &pr : polygon)
                swap(pr[0], pr[1]);
        }

        return polygon;
    };

    auto query = [&](vector<array<double, 2>> polygon) -> double {
        cout << "? " << polygon.size() << '\n';

        for (auto &pr : polygon)
            cout << pr[0] << ' ' << pr[1] << '\n';

        cout << flush;
        double s;
        cin >> s;
        return s;
    };

    auto evaluate = [&](vector<double> lengths, double x) -> double {
        double length_x = 0, intersect = 0;

        for (int i = 0; i < int(lengths.size()); i++) {
            if (i % 2 == 0) {
                double x_low = max(x, length_x);
                double x_high = min(x + 1, length_x + lengths[i]);
                intersect += max<double>(x_high - x_low, 0);
            }

            length_x += lengths[i];
        }

        return intersect;
    };

    auto solve = [&](int N, int M, bool flip) -> double {
        if (N == 1)
            return 0;

        vector<double> lengths(N, 1);
        vector<array<double, 2>> polygon = build_polygon(N, M, lengths, flip);
        double s = query(polygon);
        vector<double> candidates;

        for (int i = 0; i < N - 1; i++)
            if (i % 2 == 0)
                candidates.push_back(i + 1 - s);
            else
                candidates.push_back(i + s);

        // sort(candidates.begin(), candidates.end());
        vector<double> dividers = {0, double(N)};

        for (int i = 0; i < int(candidates.size()) - 1; i++) {
            dividers.push_back(real_rng(candidates[i], candidates[i + 1]));
            dividers.push_back(real_rng(candidates[i] + 1, candidates[i + 1] + 1));
        }

        for (int iter = 0; iter < 100; iter++)
            dividers.push_back(real_rng(0, N));

        sort(dividers.begin(), dividers.end());
        lengths.resize(dividers.size() - 1);

        for (int i = 0; i < int(lengths.size()); i++)
            lengths[i] = dividers[i + 1] - dividers[i];

        polygon = build_polygon(N, M, lengths, flip);
        s = query(polygon);
        int which = -1;
        double closest = 1e100;

        for (int i = 0; i < int(candidates.size()); i++) {
            double value = evaluate(lengths, candidates[i]);
            dbg(candidates[i], value);

            if (abs(value - s) < closest) {
                closest = abs(value - s);
                which = i;
            }
        }

        return candidates[which];
    };

    int N, M;
    cin >> N >> M;

    double x = solve(N, M, false);
    double y = solve(M, N, true);
    cout << "! " << x << ' ' << y << endl;
}