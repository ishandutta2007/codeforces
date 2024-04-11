#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e8;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m = *max_element(all(a));

    vi count(m + 1);
    for (int i : a) count[i] += 1;

    int c1 = 0, c2 = 0;
    for (int i = 1; i <= m; i++) {
        if (i < x) c1 += count[i];
        else break;
    }

    c2 = n - c1 - count[x];

    int ans = 0;
    if (count[x] == 0) {
        ans += 1;
        if (c1 <= c2)
            ans += max(0, abs(c1 - c2) - 1);
        else ans += abs(c1 - c2);
    }
    else {
        int first_pos = c1, last_pos = c1 + count[x] - 1;
        int mid = (n + 1) / 2 - 1;

        if (first_pos > mid) { //   5, 1
            ans += (first_pos - mid) * 2;
            if (n % 2 == 0) ans -= 1;
        }
        else if (mid > last_pos) { //2, 2, 5
            ans += (mid - last_pos) * 2;
            if (n % 2 != 0) ans -= 1;
        }
    }

    cout << ans << "\n";
    return 0;
}