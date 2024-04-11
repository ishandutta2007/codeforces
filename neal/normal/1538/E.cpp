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


struct variable {
    static int count_haha(const string &str) {
        int count = 0;

        for (int i = 0; i + 4 <= int(str.size()); i++)
            count += str.substr(i, 4) == "haha";

        return count;
    }

    int64_t haha;
    string first, last;

    variable(string str = "") {
        haha = count_haha(str);
        first = last = str;
        trim();
    }

    void trim() {
        if (first.size() > 3) first = first.substr(0, 3);
        if (last.size() > 3) last = last.substr(last.size() - 3);
    }

    friend variable operator+(const variable &x, const variable &y) {
        variable z;
        z.haha = x.haha + y.haha + count_haha(x.last + y.first);
        z.first = x.first + y.first;
        z.last = x.last + y.last;
        z.trim();
        return z;
    }
};

void run_case() {
    int N;
    cin >> N;
    map<string, variable> vars;
    string name, type;

    for (int i = 0; i < N; i++) {
        cin >> name >> type;

        if (type == ":=") {
            string str;
            cin >> str;
            vars[name] = variable(str);
        } else if (type == "=") {
            string a, plus, b;
            cin >> a >> plus >> b;
            assert(plus == "+");
            vars[name] = vars[a] + vars[b];
        } else {
            assert(false);
        }
    }

    cout << vars[name].haha << '\n';
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