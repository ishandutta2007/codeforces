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


int query(int a, int b) {
    cout << 1 << ' ' << a << ' ' << b << endl;
    int result;
    cin >> result;
    return result;
}

int query(int x, vector<int> s) {
    if (s.empty())
        return 0;

    cout << 2 << ' ' << x << ' ' << s.size();

    for (int si : s)
        cout << ' ' << si;

    cout << endl;
    int result;
    cin >> result;
    return result;
}

void run_case() {
    int N;
    cin >> N;
    vector<int> path = {0};

    for (int i = 1; i < N; i++) {
        int low = 0, high = i;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (query(i, path[mid]))
                high = mid;
            else
                low = mid + 1;
        }

        path.insert(path.begin() + low, i);
    }

    dbg(path);
    vector<vector<int>> sccs = {{path[0]}};

    auto build_s = [&](int count) -> vector<int> {
        vector<int> s;

        for (int i = 0; i < count; i++)
            s.insert(s.end(), sccs[i].begin(), sccs[i].end());

        return s;
    };

    for (int i = 1; i < N; i++) {
        int sc = int(sccs.size());

        if (!query(path[i], build_s(sc))) {
            sccs.push_back({path[i]});
            continue;
        }

        bool found = false;

        for (int x = sc - 1; x > 0; x--)
            if (!query(path[i], build_s(x))) {
                vector<int> combined;

                for (int y = x; y < sc; y++)
                    combined.insert(combined.end(), sccs[y].begin(), sccs[y].end());

                combined.push_back(path[i]);
                sccs.resize(x);
                sccs.push_back(combined);
                found = true;
                break;
            }

        if (!found) {
            vector<int> combined = build_s(sc);
            combined.push_back(path[i]);
            dbg(combined);
            sccs = {combined};
        }
    }

    dbg(sccs);
    vector<string> adj(N, string(N, '?'));

    for (int i = 0; i < int(sccs.size()); i++)
        for (int j = 0; j < int(sccs.size()); j++)
            for (int x : sccs[i])
                for (int y : sccs[j])
                    adj[x][y] = i <= j ? '1' : '0';

    cout << 3 << '\n';

    for (auto &row : adj)
        cout << row << '\n';

    cout << flush;
    int result;
    cin >> result;

    if (result != 1)
        exit(0);
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}