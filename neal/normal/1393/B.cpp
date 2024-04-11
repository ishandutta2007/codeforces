#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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


const int MAX = 1e5 + 5;

vector<int> freq(MAX, 0);
set<pair<int, int>> freq_set;

void update(int x, int change) {
    freq_set.erase({freq[x], x});
    freq[x] += change;
    freq_set.emplace(freq[x], x);
}

void insert(int x) {
    update(x, +1);
}

void erase(int x) {
    update(x, -1);
}

bool query() {
    auto it = freq_set.rbegin();
    int first = it->first;
    it++;
    int second = it->first;
    it++;
    int third = it->first;

    if (first >= 8)
        return true;

    if (first >= 6 && second >= 2)
        return true;

    if (first >= 4 && second >= 4)
        return true;

    if (first >= 4 && second >= 2 && third >= 2)
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    for (int i = 0; i < MAX; i++)
        freq_set.emplace(freq[i], i);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        string type;
        int x;
        cin >> type >> x;

        if (type == "+")
            insert(x);
        else
            erase(x);

        cout << (query() ? "YES" : "NO") << '\n';
    }
}