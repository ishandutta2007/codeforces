#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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


void run_case() {
    string str;
    cin >> str;
    set<pair<pair<int, int>, pair<int, int>>> segments;
    pair<int, int> location = {0, 0};
    int total = 0;

    for (char c : str) {
        pair<int, int> next_loc = location;

        if (c == 'N')
            next_loc.second++;
        else if (c == 'S')
            next_loc.second--;
        else if (c == 'E')
            next_loc.first++;
        else if (c == 'W')
            next_loc.first--;

        if (segments.emplace(min(location, next_loc), max(location, next_loc)).second)
            total += 5;
        else
            total++;

        location = next_loc;
    }

    cout << total << '\n';
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