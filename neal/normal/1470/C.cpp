#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main() {
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    auto left = [&](int index) {
        return index == 0 ? N - 1 : index - 1;
    };

    auto query = [&](int index) {
        cout << "? " << index + 1 << endl;
        int result;
        cin >> result;
        return result;
    };

    int S = int(ceil(sqrt(N))) + 5;

    for (int iter = 0; iter < S; iter++)
        query(0);

    int big = -1;

    for (int i = 0; i < S; i++) {
        int position = i * N / S;

        if (query(position) > K) {
            big = position;
            break;
        }
    }

    assert(big >= 0);
    int jump = N / 2;

    while (jump > 0) {
        int below = (big + N - jump) % N;

        if (query(below) > K)
            big = below;

        jump = jump == 1 ? 0 : (jump + 1) / 2;
    }

    cout << "! " << left(big) + 1 << endl;
}