#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int N, K;
    cin >> N >> K;
    vector<int> cost(2 * K, N);
    vector<int> change(2 * K, 0);
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    for (int i = 0; i < N / 2; i++) {
        int &a = A[i], &b = A[N - 1 - i];
        a--; b--;

        change[a + b]--;
        change[a + b + 1]++;

        int low = min(a, b);
        int high = max(a, b) + (K - 1);

        change[low]--;
        change[high + 1]++;
    }

    int change_sum = 0;

    for (int x = 0; x < 2 * K; x++) {
        change_sum += change[x];
        cost[x] += change_sum;
    }

    cout << *min_element(cost.begin(), cost.end()) << '\n';
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