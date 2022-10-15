// ./c-points-on-plane.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

using T = tuple<int, int, int>;
const int MN = 1e6 + 1, BS = 1000;
int N;
T pts[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y, i};
    }
    sort(pts, pts+N, [&] (const T &_, const T &__) {
        auto [a, b, ___] = _;
        auto [c, d, ____] = __;
        int b1 = a/BS, b2 = c/BS;
        if (b1 == b2) {
            if (b1 % 2) return b > d;
            else return b < d;
        }
        return b1 < b2;
    });
    for (auto i = 0; i < N; i++)
        cout << get<2>(pts[i])+1 << " \n"[i == N-1];

    return 0;
}