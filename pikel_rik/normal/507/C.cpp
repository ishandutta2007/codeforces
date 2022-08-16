#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

ll h, n;

ll recurse(ll curn, ll curh, int d = -1) {
    if (curh == 0)
        return 0;

    ll mid = (1LL << (curh - 1));

    if (curn <= mid) {
        if (d == -1)
            return 1 + recurse(curn, curh - 1, 1);
        return (1LL << curh) + recurse(curn, curh - 1, 1);
    }

    if (d == -1)
        return (1LL << curh) + recurse(curn - mid, curh - 1, -1);
    return 1 + recurse(curn - mid, curh - 1, -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> h >> n;
    cout << recurse(n, h) << "\n";
    return 0;
}