#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

const int B = 20;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> cnt(B);
    int base = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            base++;
            a[i] /= 2;
        }
        int c = i + 1, cur = 0;
        while (c % 2 == 0) {
            cur++;
            c /= 2;
        }
        cnt[cur]++;
    }
    for (int i = B-1; i >= 0; i--) {
        while (base < n && cnt[i]) {
            base += i;
            cnt[i]--;
            ans++;
        }
    }
    if (base >= n)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}