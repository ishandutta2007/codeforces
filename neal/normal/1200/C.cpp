#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    int Q;
    cin >> N >> M >> Q;
    long long G = __gcd(N, M);

    while (Q-- > 0) {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sy--; ey--;

        long long s_section = sy / ((sx == 1 ? N : M) / G);
        long long e_section = ey / ((ex == 1 ? N : M) / G);
        cout << (s_section == e_section ? "YES" : "NO") << '\n';
    }
}