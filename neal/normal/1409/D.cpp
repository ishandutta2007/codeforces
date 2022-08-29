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


void run_case() {
    uint64_t N, S;
    cin >> N >> S;
    string str = to_string(N);
    str = "0" + str;
    int n = int(str.size());
    vector<uint64_t> candidates = {N};

    for (int i = n - 1; i >= 0; i--) {
        if (str[i] != '9') {
            str[i]++;
            candidates.push_back(stoull(str));
        }

        str[i] = '0';
    }

    auto &&sum_of_digits = [](uint64_t x) {
        uint64_t sum = 0;

        while (x != 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    };

    uint64_t best = 1e19;

    for (uint64_t cand : candidates)
        if (sum_of_digits(cand) <= S)
            best = min(best, cand - N);

    cout << best << '\n';
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