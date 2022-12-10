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

pii get(int x) {
    for (int i = 0; i <= x; i += 5)
        if ((x - i) % 3 == 0)
            return pii(i / 5, (x - i) / 3);
    return pii(-1, -1);
}

int solve() {
    int n;
    cin >> n;
    for (int i = 0; i * 7 <= n; i++) {
        pii cur = get(n - i * 7);
        if (cur.L != -1)
            return cout << cur.R << ' ' << cur.L << ' ' << i << '\n', 0;
    }
    cout << -1 << '\n';
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