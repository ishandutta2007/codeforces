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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> H(N);

    for (auto &h : H)
        cin >> h;

    vector<int> dp(N);
    dp[0] = 0;
    vector<int> maxima = {0}, minima = {0};

    auto &&process_height = [&]<typename Compare>(int i, vector<int> &stack, const Compare &&compare) {
        while (!stack.empty() && !compare(H[stack.back()], H[i])) {
            int previous = H[stack.back()];
            stack.pop_back();

            if (compare(H[i], previous) && !stack.empty())
                dp[i] = min(dp[i], dp[stack.back()] + 1);
        }

        stack.push_back(i);
    };

    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + 1;
        process_height(i, maxima, greater<int>());
        process_height(i, minima, less<int>());
    }

    cout << dp.back() << '\n';
}