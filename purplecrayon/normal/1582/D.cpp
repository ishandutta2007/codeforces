#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    vector<int> b(n, 1);
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int c = a[i];
        if (c < 0) b[i] *= -1;
        if (sum > 0) b[i] *= -1;
        sum += c * b[i];
    }
    if (sum < 0) {
        for (int i = 0; i < n-1; i++) b[i] *= -1;
        sum *= -1;
    }
    if (a[n-1] < 0) b[n-1] *= -1, a[n-1] *= -1;
    if (sum == 0) {
        sum -= b[n-2] * a[n-2];
        b[n-2] *= -1;
        sum += b[n-2] * a[n-2];
    }

    int tot = std::lcm(a[n-1], sum);

    int one = tot / sum, two = tot / a[n-1];
    for (int i = 0; i < n-1; i++) b[i] *= one;
    b[n-1] *= two, b[n-1] *= -1;

    for (auto c : b) cout << c << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}