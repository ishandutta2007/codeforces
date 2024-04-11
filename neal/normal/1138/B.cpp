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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    string A, B;
    cin >> N >> A >> B;
    int counts[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < N; i++)
        counts[A[i] - '0'][B[i] - '0']++;

    for (int both = 0; both <= counts[1][1]; both++)
        for (int right = 0; right <= counts[0][1]; right++) {
            int balance = both - (counts[1][1] - both) - (counts[0][1] - right);

            if (balance > 0)
                continue;

            if (both + right > N / 2)
                continue;

            int need = -balance;

            if (need > counts[1][0] || both + right + need > N / 2)
                continue;

            int left = need;
            int neither = N / 2 - both - right - left;

            if (neither < 0 || neither > counts[0][0])
                continue;

            vector<int> first;

            for (int i = 0; i < N; i++) {
                int &count = counts[A[i] - '0'][B[i] - '0'];

                if (A[i] == '0' && B[i] == '0') {
                    if (--count < neither)
                        first.push_back(i);
                } else if (A[i] == '0' && B[i] == '1') {
                    if (--count < right)
                        first.push_back(i);
                } else if (A[i] == '1' && B[i] == '0') {
                    if (--count < left)
                        first.push_back(i);
                } else if (A[i] == '1' && B[i] == '1') {
                    if (--count < both)
                        first.push_back(i);
                }
            }

            output_vector(first, true);
            return 0;
        }

    cout << -1 << '\n';
}