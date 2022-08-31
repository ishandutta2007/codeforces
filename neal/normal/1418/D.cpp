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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    set<int> positions;
    multiset<int> gaps;

    auto &&add_position = [&](int p) {
        auto it = positions.insert(p).first;

        if (next(it) != positions.end())
            gaps.insert(*next(it) - p);

        if (it != positions.begin()) {
            gaps.insert(p - *prev(it));

            if (next(it) != positions.end())
                gaps.erase(gaps.find(*next(it) - *prev(it)));
        }
    };

    auto &&erase_position = [&](int p) {
        auto it = positions.find(p);
        assert(it != positions.end());

        if (next(it) != positions.end())
            gaps.erase(gaps.find(*next(it) - p));

        if (it != positions.begin()) {
            gaps.erase(gaps.find(p - *prev(it)));

            if (next(it) != positions.end())
                gaps.insert(*next(it) - *prev(it));
        }

        positions.erase(it);
    };

    auto &&query = [&] {
        if (positions.size() <= 2)
            return 0;

        return *(--positions.end()) - *positions.begin() - *(--gaps.end());
    };

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        add_position(p);
    }

    cout << query() << '\n';

    for (int q = 0; q < Q; q++) {
        int type, x;
        cin >> type >> x;

        if (type == 0)
            erase_position(x);
        else
            add_position(x);

        cout << query() << '\n';
    }
}