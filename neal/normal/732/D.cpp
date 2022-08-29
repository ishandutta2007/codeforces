#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
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

    int N, M;
    cin >> N >> M;
    vector<int> D(N);

    for (auto &d : D) {
        cin >> d;
        d--;
    }

    vector<int> A(M);

    for (auto &a : A)
        cin >> a;

    auto possible = [&](int days) {
        vector<int> last(M, -1);

        for (int i = 0; i < days; i++)
            if (D[i] >= 0)
                last[D[i]] = i;

        if (*min_element(last.begin(), last.end()) < 0)
            return false;

        vector<int> order(M);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return last[a] < last[b];
        });

        int current = 0;
        int extra = 0;

        for (int x : order) {
            int day = last[x];
            extra += day - current;
            current = day + 1;

            if (extra < A[x])
                return false;

            extra -= A[x];
        }

        return true;
    };

    int low = 0, high = N + 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << (low <= N ? low : -1) << '\n';
}