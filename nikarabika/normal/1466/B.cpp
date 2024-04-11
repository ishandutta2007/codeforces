//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

int solve() {
    int n;
    cin >> n;
    int cnt[2 * n + 1] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x, x--;
        cnt[x]++;
    }
    int cur = 0;
    int ans = 0;
    for (int i = 0; i <= n + n; i++)
        if (cnt[i])
            cur += cnt[i] - 1, ans++;
        else {
            ans += cur > 0;
            cur = 0;
        }
    cout << ans << '\n';
    return 0;
}