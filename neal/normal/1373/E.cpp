#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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


const int LIMIT = 1e5;
const int MAX_DIGITS = 18;
const int BUFFER = 10;

array<int, LIMIT> digit_sum;
set<int64_t> candidates;

void precompute() {
    digit_sum[0] = 0;

    for (int i = 1; i < LIMIT; i++)
        digit_sum[i] = digit_sum[i / 10] + i % 10;

    candidates = {0};

    for (int first = 1; first <= 9; first++)
        for (int nines = 0; nines <= MAX_DIGITS - 2; nines++) {
            string str = char('0' + first) + string(nines, '9') + '0';
            candidates.insert(stoll(str));
        }

    vector<int64_t> current(candidates.begin(), candidates.end());

    for (int64_t x : current)
        for (int i = -BUFFER; i <= BUFFER; i++)
            candidates.insert(max(x + i, INT64_C(0)));

    cerr << candidates.size() << endl;
}

int get_digit_sum(int64_t x) {
    int sum = 0;

    while (x > 0) {
        sum += digit_sum[x % LIMIT];
        x /= LIMIT;
    }

    return sum;
}

void run_case() {
    int N, K;
    cin >> N >> K;

    for (int64_t x : candidates) {
        int sum = 0;

        for (int i = 0; i <= K; i++)
            sum += get_digit_sum(x + i);

        if (sum == N) {
            cout << x << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    precompute();

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}