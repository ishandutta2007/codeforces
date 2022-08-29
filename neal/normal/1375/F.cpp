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


const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    array<int64_t, 3> A;
    cin >> A[0] >> A[1] >> A[2];
    cout << "First" << endl;
    cout << INF << endl;

    int which;
    cin >> which;
    which--;
    A[which] += INF;

    array<int64_t, 3> sorted = A;
    sort(sorted.begin(), sorted.end());

    int64_t add = 2 * sorted[2] - sorted[0] - sorted[1];
    cout << add << endl;
    cin >> which;
    which--;
    A[which] += add;

    sorted = A;
    sort(sorted.begin(), sorted.end());
    assert(sorted[1] - sorted[0] == sorted[2] - sorted[1]);
    cout << sorted[1] - sorted[0] << endl;
}