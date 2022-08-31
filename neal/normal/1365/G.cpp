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


const int Q = 13;
const int HALF = Q / 2;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> when(N);

    for (int i = 0, mask = 0; i < N; i++) {
        while (__builtin_popcount(mask) != HALF)
            mask++;

        when[i] = mask++;
    }

    vector<int64_t> result(Q, 0);

    for (int q = 0; q < Q; q++) {
        vector<int> indices;

        for (int i = 0; i < N; i++)
            if (when[i] >> q & 1)
                indices.push_back(i);

        if (!indices.empty()) {
            cout << "? " << indices.size();

            for (int index : indices)
                cout << ' ' << index + 1;

            cout << endl;
            cin >> result[q];
        }
    }

    cout << '!';

    for (int i = 0; i < N; i++) {
        int64_t answer = 0;

        for (int q = 0; q < Q; q++)
            if ((when[i] >> q & 1) == 0)
                answer |= result[q];

        cout << ' ' << answer;
    }

    cout << endl;
}