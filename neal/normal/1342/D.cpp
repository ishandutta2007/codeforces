#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
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
vector<int> freq;
vector<int> C;
vector<vector<int>> solution;

bool possible(int T) {
    solution.assign(T, {});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int t = 0; t < T; t++)
        pq.emplace(0, t);

    for (int k = K; k > 0; k--)
        for (int iter = 0; iter < freq[k]; iter++) {
            if (pq.top().first >= C[k])
                return false;

            pair<int, int> top = pq.top();
            pq.pop();
            solution[top.second].push_back(k);
            top.first++;
            pq.push(top);
        }

    return true;
}

void output_solution(int T) {
    cout << T << '\n';

    for (vector<int> &test_case : solution) {
        cout << test_case.size();

        for (int x : test_case)
            cout << ' ' << x;

        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> K;
    freq.assign(K + 1, 0);

    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;
        freq[m]++;
    }

    C.resize(K + 1);

    for (int k = 1; k <= K; k++)
        cin >> C[k];

    int low = 1, high = N;

    while (low < high) {
        int mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    possible(low);
    output_solution(low);
}