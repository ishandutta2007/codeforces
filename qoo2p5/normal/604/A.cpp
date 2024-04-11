#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

ll m[5];
int w[5];
ll b[5] = {500, 1000, 1500, 2000, 2500};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < 5; i++) {
		cin >> w[i];
	}

	ll hs, hf;
	cin >> hs >> hf;

	ll ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += max(b[i] / 10 * 3, b[i] - m[i] * b[i] / 250 - 50 * w[i]);
	}

	ans += hs * 100 - hf * 50;
	cout << ans << endl;

    return 0;
}