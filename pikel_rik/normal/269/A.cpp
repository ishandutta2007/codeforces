#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n;
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        if (a[i].first - a[i-1].first >= 15)
            continue;

        int possible = (1 << (2 * (a[i].first - a[i-1].first)));
        if (possible * (ll)a[i].second >= a[i-1].second)
            continue;
        a[i].second += (a[i-1].second + possible - 1) / possible - a[i].second;
    }

    if (a[n-1].second == 1) {
        cout << a[n-1].first + 1 << "\n";
        return 0;
    }

    cout << a[n-1].first + (int)(ceil(log2(a[n-1].second) / 2));
    return 0;
}