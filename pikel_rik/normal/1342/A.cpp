#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;

        if (b < 2 * a)
            cout << b * min(x, y) + a * (max(x, y) - min(x, y)) << "\n";
        else cout << a * (x + y) << "\n";
    }
    return 0;
}