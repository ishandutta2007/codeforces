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
    n <<= 1;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> w;
    int mx = a[0];
    int cur = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) {
            w.PB(cur);
            cur = 0;
            mx = 0;
        }
        cur++;
        smax(mx, a[i]);
    }
    w.PB(cur);
    bool *dp[sz(w) + 1];
    dp[0] = (bool *) calloc(n + 1, sizeof(bool));
    dp[0][0] = true;
    for (int i = 0; i < sz(w); i++) {
        dp[i + 1] = (bool *) calloc(n + 1, sizeof(bool));
        for (int j = 0; j <= n; j++)
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                if (j + w[i] <= n)
                    dp[i + 1][j + w[i]] = true;
            }
    }
    if (dp[sz(w)][n / 2])
        cout << "YES\n";
    else
        cout << "NO\n";
    for (int i = 0; i <= sz(w); i++)
        free(dp[i]);
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