#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        if (n > 2) cout << 2 * m << "\n";
        else if (n == 2) cout << m << "\n";
        else cout << "0\n";
    }
    return 0;
}