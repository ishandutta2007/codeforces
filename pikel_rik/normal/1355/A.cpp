#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

pair<int, int> f(ll x) {
    if (x == 0)
        return {0, 0};

    int m1 = 10, m2 = -1;
    while (x > 0) {
        m1 = min((ll)m1, x % 10);
        m2 = max((ll)m2, x % 10);
        x /= 10;
    }
    return {m1, m2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a1, k;
        cin >> a1 >> k;

        ll a = a1;

        for (int i = 2; i <= k; i++) {
            pair<int, int> temp = f(a);
            a += temp.first * temp.second;
            if (temp.first == 0 or temp.second == 0)
                break;
        }

        cout << a << "\n";
    }
    return 0;
}