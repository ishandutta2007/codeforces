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


const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> W(N);

    for (auto &w : W)
        cin >> w;

    vector<array<int, 2>> friends(M);
    vector<int> wanted(N, 0);
    vector<vector<int>> who_wants(N);

    for (int i = 0; i < M; i++) {
        auto &f = friends[i];
        cin >> f[0] >> f[1];
        f[0]--; f[1]--;
        who_wants[f[0]].push_back(i);
        who_wants[f[1]].push_back(i);
        wanted[f[0]]++;
        wanted[f[1]]++;
    }

    vector<bool> ok(M, false);
    vector<bool> handled(N, false);
    vector<int> enough;

    for (int i = 0; i < N; i++)
        if (W[i] >= wanted[i]) {
            enough.push_back(i);
            handled[i] = true;
        }

    auto &&decrement = [&](int food) {
        wanted[food]--;

        if (!handled[food] && wanted[food] <= W[food]) {
            enough.push_back(food);
            handled[food] = true;
        }
    };

    vector<int> order;

    while (!enough.empty()) {
        int food = enough.back();
        enough.pop_back();
        W[food] = -INF;

        for (int x : who_wants[food])
            if (!ok[x]) {
                ok[x] = true;
                order.push_back(x);
                decrement(friends[x][0]);
                decrement(friends[x][1]);
            }
    }

    for (int x = 0; x < M; x++)
        if (!ok[x]) {
            cout << "DEAD" << '\n';
            return 0;
        }

    cout << "ALIVE" << '\n';
    reverse(order.begin(), order.end());
    output_vector(order, true);
}