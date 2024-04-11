#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct fraction {
    static const bool CHECK_OVERFLOW64 = true;
    // TODO: consider setting AUTO_REDUCE = false for faster code. In this case, remember to call reduce() at the end.
    static const bool AUTO_REDUCE = true;

    static int cross_sign(const fraction &a, const fraction &b) {
        if (CHECK_OVERFLOW64) {
            long double double_value = (long double) a.numer * b.denom - (long double) b.numer * a.denom;

            if (abs(double_value) > 1e18)
                return double_value > 0 ? +1 : -1;
        }

        uint64_t uint64_value = (uint64_t) a.numer * b.denom - (uint64_t) b.numer * a.denom;

        if (uint64_value == 0)
            return 0;

        return uint64_value >> 63 ? -1 : +1;
    }

    long long numer, denom;

    fraction(long long n = 0, long long d = 1) : numer(n), denom(d) {
        check_denom();

        if (AUTO_REDUCE)
            reduce();
    }

    void check_denom() {
        assert(denom != 0);

        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
    }

    void reduce() {
        long long g = __gcd(abs(numer), denom);
        numer /= g;
        denom /= g;
    }

    bool is_integer() const {
        return denom == 1;
    }

    friend fraction operator+(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom + b.numer * a.denom, a.denom * b.denom);
    }

    friend fraction operator-(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom - b.numer * a.denom, a.denom * b.denom);
    }

    friend fraction operator*(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.numer, a.denom * b.denom);
    }

    friend fraction operator/(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom, a.denom * b.numer);
    }

    fraction& operator+=(const fraction &other) { return *this = *this + other; }
    fraction& operator-=(const fraction &other) { return *this = *this - other; }
    fraction& operator*=(const fraction &other) { return *this = *this * other; }
    fraction& operator/=(const fraction &other) { return *this = *this / other; }

    fraction& operator++() { numer += denom; return *this; }
    fraction& operator--() { numer -= denom; return *this; }

    fraction operator++(int) { fraction before = *this; ++*this; return before; }
    fraction operator--(int) { fraction before = *this; --*this; return before; }

    fraction operator-() const {
        return fraction(-numer, denom);
    }

    fraction inv() const {
        return fraction(denom, numer);
    }

    bool operator==(const fraction &other) const { return cross_sign(*this, other) == 0; }
    bool operator!=(const fraction &other) const { return cross_sign(*this, other) != 0; }
    bool operator<(const fraction &other) const { return cross_sign(*this, other) < 0; }
    bool operator>(const fraction &other) const { return cross_sign(*this, other) > 0; }
    bool operator<=(const fraction &other) const { return cross_sign(*this, other) <= 0; }
    bool operator>=(const fraction &other) const { return cross_sign(*this, other) >= 0; }

    double to_double() const {
        return (double) numer / denom;
    }

    friend ostream& operator<<(ostream& out, const fraction &frac) {
        return out << frac.numer << '/' << frac.denom;
    }
};


const long long LL_INF = (long long) 2e18 + 5;

int N;
long long R;
vector<bool> is_parallel;
vector<vector<int>> children;

void parse_input(string S) {
    N = 0;
    vector<int> stack = {-1};
    int level = 0;
    vector<pair<int, int>> edges;

    for (char c : S)
        if (c == '(') {
            stack[level] = N++;
            stack.push_back(-1);
            is_parallel.push_back(false);

            if (level > 0)
                edges.emplace_back(stack[level - 1], stack[level]);

            level++;
        } else if (c == '*') {
            stack[level] = N++;
            is_parallel.push_back(false);

            if (level > 0)
                edges.emplace_back(stack[level - 1], stack[level]);
        } else if (c == 'P') {
            assert(level > 0);
            is_parallel[stack[level - 1]] = true;
        } else if (c == 'S') {
            assert(level > 0);
            is_parallel[stack[level - 1]] = false;
        } else if (c == ')') {
            assert(level > 0);
            stack.pop_back();
            level--;
        }

    children.assign(N, {});

    for (pair<int, int> &edge : edges)
        children[edge.first].push_back(edge.second);

    // cerr << "N = " << N << endl;

    // for (pair<int, int> &edge : edges)
    //     cerr << edge.first << ' ' << edge.second << endl;

    // for (int i = 0; i < N; i++)
    //     if (is_parallel[i])
    //         cerr << i << " is parallel" << endl;
}

vector<long long> answer;
vector<long long> multiplier;

void solve_multipliers(int node) {
    if (children[node].empty()) {
        multiplier[node] = 1;
        return;
    }

    for (int child : children[node])
        solve_multipliers(child);

    if (!is_parallel[node]) {
        multiplier[node] = LL_INF;

        for (int child : children[node])
            multiplier[node] = min(multiplier[node], multiplier[child]);
    } else {
        multiplier[node] = 0;

        for (int child : children[node])
            multiplier[node] += multiplier[child];
    }
}

void solve_answers(int node, fraction goal) {
    if (children[node].empty()) {
        assert(goal.is_integer());
        answer[node] = goal.numer;
        return;
    }

    if (!is_parallel[node]) {
        int min_child = -1;

        for (int child : children[node])
            if (multiplier[child] == multiplier[node])
                min_child = child;

        for (int child : children[node])
            if (child == min_child)
                solve_answers(child, goal);
            else
                solve_answers(child, 0);
    } else {
        for (int child : children[node])
            solve_answers(child, goal * fraction(multiplier[node], multiplier[child]));
    }
}

void solve_case() {
    cin >> R;
    string S;
    getline(cin, S);
    parse_input(S);

    multiplier.assign(N, -1);
    answer.assign(N, -1);
    solve_multipliers(0);
    solve_answers(0, R);

    cout << "REVOLTING";

    for (int i = 0; i < N; i++)
        if (answer[i] >= 0)
            cout << ' ' << answer[i];

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}