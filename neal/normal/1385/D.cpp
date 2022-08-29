#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
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


int N;
string S;
map<pair<int, int>, int> save;

int solve(int start, int end) {
    int length = end - start;
    int level = __builtin_ctz(N) - __builtin_ctz(length);
    char need = char('a' + level);

    if (length == 1)
        return S[start] != need;

    if (save.find({start, end}) != save.end())
        return save[{start, end}];

    int mid = (start + end) / 2;
    int left = 0, right = 0;

    for (int i = start; i < mid; i++)
        left += S[i] != need;

    for (int i = mid; i < end; i++)
        right += S[i] != need;

    int answer = min(left + solve(mid, end), solve(start, mid) + right);
    return save[{start, end}] = answer;
}

void run_case() {
    cin >> N >> S;
    save.clear();
    cout << solve(0, N) << '\n';
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