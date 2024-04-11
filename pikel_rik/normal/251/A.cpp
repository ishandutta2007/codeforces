#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(all(a), a[i] + d) - a.begin();
        pos -= 1;
        if (pos > i + 1)
            ans += (pos - i) * (ll)(pos - i - 1) / 2;
    }

    cout << ans << "\n";
    return 0;
}