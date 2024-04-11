#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define db(v) cout << #v << " is " << v << endl
using namespace std;
using lint = long long;
using pii = pair<int, int>;
using pll = pair<lint, lint>;

lint gcd(lint a, lint b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    lint n; cin >> n;
    lint a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    lint maks = *max_element(a, a + n);
    lint ans = 0;
    lint cnt = 0;
    for (int i = 0; i < n; i++) {
        ans = gcd(ans, maks - a[i]);
    }
    for (int i = 0; i < n; i++) {
        cnt += (maks - a[i]) / ans;
    }
    cout << cnt << " " << ans << "\n";
}