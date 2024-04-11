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

int get(int x, int y) {
    return max(x, y) - min(x, y);
}

LL get(int a, int b, int c, int d) {
    LL arr[4] = {a, b, c, d};
    sort(arr, arr + 4);
    return arr[1] - arr[0] + arr[2] - arr[1] + arr[3] - arr[1];
}

int solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    LL ans = 0;
    for (int i = 0; i < n - 1 - i; i++)
        for (int j = 0; j < m - 1 - j; j++)
            ans += get(a[i][j], a[i][m - 1 - j], a[n - 1 - i][j], a[n - 1 - i][m - 1 - j]);
    int imid = n / 2;
    int jmid = m / 2;
    if (n & 1)
        for (int j = 0; j < m - 1 - j; j++)
            ans += get(a[imid][j], a[imid][m - 1 - j]);
    if (m & 1)
        for (int i = 0; i < n - 1 - i; i++)
            ans += get(a[i][jmid], a[n - 1 - i][jmid]);
    cout << ans << '\n';
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