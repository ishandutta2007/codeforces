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


int N, K;
string S;
vector<vector<int>> fastest;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> K >> S;

    while (true) {
        vector<int> swaps;

        for (int i = 0; i < N - 1; i++)
            if (S[i] > S[i + 1])
                swaps.push_back(i);

        if (swaps.empty())
            break;

        for (int s : swaps)
            swap(S[s], S[s + 1]);

        fastest.push_back(swaps);
    }

    if (K < (int) fastest.size()) {
        cout << -1 << '\n';
        return 0;
    }

    int extra = K - fastest.size();
    vector<vector<int>> solution;

    for (vector<int> &swaps : fastest) {
        int S = swaps.size();
        int take = min(extra, S - 1);
        extra -= take;

        for (int i = 0; i < take; i++)
            solution.push_back({swaps[i]});

        if (take == 0)
            solution.push_back(swaps);
        else
            solution.push_back(vector<int>(swaps.begin() + take, swaps.end()));
    }

    if (extra > 0) {
        cout << -1 << '\n';
        return 0;
    }

    assert((int) solution.size() == K);

    for (vector<int> &swaps : solution) {
        cout << swaps.size();

        for (int x : swaps)
            cout << ' ' << x + 1;

        cout << '\n';
    }
}