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


const int INF = 1e9 + 5;

void run_case() {
    int N;
    cin >> N;
    vector<vector<bool>> segments(N - 1);
    vector<int> lengths(N, 0);
    vector<int> occur(N, 0);

    for (int s = 0; s < N - 1; s++) {
        int k;
        cin >> k;
        lengths[s] = k;
        segments[s].assign(N, false);

        while (k-- > 0) {
            int a;
            cin >> a;
            a--;
            segments[s][a] = true;
            occur[a]++;
        }
    }

    vector<int> P(N, -1);
    vector<bool> done;
    vector<bool> seg_alive;
    vector<int> occur_copy = occur;
    bool valid;

    for (int first = 0; first < N; first++) {
        seg_alive.assign(N - 1, true);
        done.assign(N, false);
        done[first] = true;
        P[0] = first;
        valid = true;

        for (int index = N - 1; index > 0; index--) {
            int best = -1;

            for (int i = 0; i < N; i++)
                if (!done[i] && occur[i] == 1)
                    best = i;

            if (best < 0) {
                valid = false;
                break;
            }

            P[index] = best;
            done[best] = true;

            for (int s = 0; s < N - 1; s++)
                if (seg_alive[s] && segments[s][best]) {
                    seg_alive[s] = false;

                    for (int i = 0; i < N; i++)
                        if (segments[s][i])
                            occur[i]--;
                }
        }

        dbg(P, valid);
        occur = occur_copy;

        if (!valid)
            continue;

        vector<bool> seen(N, false);

        for (int s = 0; s < N - 1; s++) {
            int low = INF, high = -INF;

            for (int i = 0; i < N; i++)
                if (segments[s][P[i]]) {
                    low = min(low, i);
                    high = max(high, i);
                }

            if (high - low + 1 != lengths[s])
                valid = false;

            seen[high] = true;
        }

        for (int i = 1; i < N; i++)
            if (!seen[i])
                valid = false;

        if (valid)
            break;
    }

    assert(valid);

    for (int i = 0; i < N; i++)
        cout << P[i] + 1 << (i < N - 1 ? ' ' : '\n');
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