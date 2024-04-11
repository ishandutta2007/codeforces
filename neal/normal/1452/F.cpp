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

int64_t ceil_div(int64_t a, int64_t b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<int64_t> C(N);

    for (auto &c : C)
        cin >> c;

    auto query = [&](int x, int64_t k) -> int64_t {
        int64_t maximum = 0;

        for (int i = 0; i < N; i++)
            maximum += C[i] << i;

        if (maximum < k)
            return -1;

        int64_t already = 0, potential = 0;

        for (int i = 0; i <= x; i++) {
            already += C[i];
            potential += C[i] << i;
        }

        if (already >= k)
            return 0;

        int64_t remain = k - already;
        int64_t ops = 0;
        dbg(remain);

        for (int i = x + 1; i < N; i++) {
            int64_t c = C[i];
            int64_t generate = 1LL << (i - x);
            int64_t useful = min(remain / generate, c);
            remain -= useful * generate;
            ops += useful * (generate - 1);
            c -= useful;
            potential += useful << i;
            dbg(i, useful);

            if (c > 0) {
                dbg(i, ops, remain, generate);
                assert(remain < generate);

                if (potential >= k)
                    break;

                int64_t extra = ceil_div(k - potential, 1LL << x);
                assert(extra <= remain);
                dbg(extra);

                while (extra + (extra & -extra) <= remain)
                    extra += extra & -extra;

                remain -= extra;
                potential += extra << x;

                for (int level = x + 1; level <= i; level++) {
                    extra = (extra + 1) / 2;
                    ops += extra;
                    dbg(level, extra);
                }

                dbg(remain);
                break;
            }
        }

        ops += max<int64_t>(remain, 0);
        return ops;
    };

    for (int q = 0; q < Q; q++) {
        int type, x;
        int64_t k;
        cin >> type >> x >> k;

        if (type == 1)
            C[x] = k;
        else
            cout << query(x, k) << '\n';
    }
}