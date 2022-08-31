#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, x, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    multiset<int> s;
    for (int i = 0; i < n; i++) s.insert(b[i]);

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            c += n - i;
            break;
        }
        auto it = s.lower_bound(x - a[i]);

        if (it != s.end()) {
            c += 1;
            s.erase(it);
        }
    }

    cout << 1 << " " << c << "\n";
    return 0;
}