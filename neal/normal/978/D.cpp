#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int64_t> A(N);

    for (auto &a : A)
        cin >> a;

    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int64_t best = 1e18;

    for (int64_t D = A[1] - A[0] - 2; D <= A[1] - A[0] + 2; D++)
        for (int64_t a = A[0] - 1; a <= A[0] + 1; a++) {
            int64_t cost = 0;
            bool fail = false;

            for (int i = 0; i < N; i++) {
                int64_t need = a + i * D;

                if (abs(A[i] - need) > 1) {
                    fail = true;
                    break;
                }

                cost += abs(A[i] - need);
            }

            if (!fail)
                best = min(best, cost);
        }

    cout << (best < 1e17 ? best : -1) << '\n';
}