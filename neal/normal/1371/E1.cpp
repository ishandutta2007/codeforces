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

    int N, P;
    cin >> N >> P;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    auto &&count_at_most = [&](int a) {
        return int(upper_bound(A.begin(), A.end(), a) - A.begin());
    };

    vector<int> freq(P, 0);
    vector<int> save(N, 0);
    int answer = 0;
    vector<int> good;

    for (int diff = -N; diff < N; diff++) {
        if (diff >= 0) {
            int candidate = A.back() - N + diff;
            int mod = candidate % P;
            if (mod < 0) mod += P;

            if (freq[mod] == 0) {
                answer++;
                good.push_back(candidate);
            }

            freq[save[diff]]--;
        }

        int value = A.back() + diff;
        int mod = (value - count_at_most(value)) % P;
        if (mod < 0) mod += P;

        if (diff < 0)
            save[N + diff] = mod;

        freq[mod]++;
    }

    cout << answer << '\n';
    output_vector(good);
}