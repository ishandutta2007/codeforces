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

template<typename T1, typename T2>
bool maximize(T1 &a, const T2 &b) {
    if (a < T1(b)) {
        a = T1(b);
        return true;
    }

    return false;
}


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    int Z = int(count(A.begin(), A.end(), 0));
    int H = Z / 2;

    if (H == 0 || Z == N) {
        cout << 0 << '\n';
        return;
    }

    vector<array<int, 2>> LR(N + 1, {0, 0});

    for (int i = 0, z = 0; i < N; i++)
        if (A[i] == 0) {
            z++;
        } else {
            if (z >= H)
                maximize(LR[A[i]][1], Z - z);

            if (z <= Z - H)
                maximize(LR[A[i]][0], z);
        }

    vector<bool> matched(N + 1, false);
    int answer = 0;

    for (int dim = 0; dim < 2; dim++) {
        vector<pair<array<int, 2>, int>> options(N);

        for (int a = 1; a <= N; a++)
            options[a - 1] = {{LR[a][dim], LR[a][!dim]}, a};

        sort(options.rbegin(), options.rend());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int x = N, i = 0; x > 0; x--) {
            while (i < N && options[i].first[0] >= x) {
                if (!matched[options[i].second])
                    pq.emplace(options[i].first[1], options[i].second);

                i++;
            }

            if (!pq.empty()) {
                auto top = pq.top(); pq.pop();
                matched[top.second] = true;
                answer++;
            }
        }
    }

    answer = min(answer, H);
    cout << answer << '\n';
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