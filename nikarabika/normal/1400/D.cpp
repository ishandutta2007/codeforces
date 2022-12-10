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

int solve() {
    int n;
    cin >> n;
    int a[n];
    LL acnt[n] = {0LL},
       cnt[n] = {0LL};
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        acnt[a[i]]++;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        acnt[a[i]]--;
        memset(cnt, 0, n * 8);
        LL cur = 0;
        for (int j = i + 1; j < n; j++) {
            cur -= cnt[a[j]] * (acnt[a[j]] - cnt[a[j]]);
            acnt[a[j]]--;
            cur += cnt[a[j]] * (acnt[a[j]] - cnt[a[j]]);

            if (a[j] == a[i])
                ans += cur;
            
            cur -= cnt[a[j]] * (acnt[a[j]] - cnt[a[j]]);
            acnt[a[j]]++;
            cnt[a[j]]++;
            cur += cnt[a[j]] * (acnt[a[j]] - cnt[a[j]]);
        }
    }
    cout << ans << '\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}