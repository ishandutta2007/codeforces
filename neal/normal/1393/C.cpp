#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
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


int N;
vector<int> freq, my_freq;

bool possible(int gap) {
    my_freq = freq;
    vector<vector<int>> reinsert(2 * N + 1);

    struct compare_index {
        bool operator()(int x, int y) {
            return my_freq[x] < my_freq[y];
        }
    };

    priority_queue<int, vector<int>, compare_index> pq;

    for (int x = 0; x <= N; x++)
        pq.push(x);

    for (int i = 0; i < N; i++) {
        for (int x : reinsert[i])
            pq.push(x);

        if (pq.empty())
            return false;

        int top = pq.top(); pq.pop();

        if (my_freq[top] <= 0)
            return false;

        my_freq[top]--;
        reinsert[i + gap].push_back(top);
    }

    return true;
}

void run_case() {
    cin >> N;
    vector<int> A(N);
    freq.assign(N + 1, 0);

    for (auto &a : A) {
        cin >> a;
        freq[a]++;
    }

    int low = 1, high = N - 1;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low - 1 << '\n';
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